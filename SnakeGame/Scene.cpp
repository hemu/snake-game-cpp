#include "Scene.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <set>
#include "Collidable.h"
#include "Consumable.h"
#include "Player.h"
#include "SignalManager.h"
#include "World.h"

#define CELL_WIDTH 20
#define CELL_HEIGHT 20

Scene::Scene(Camera &camera, Player &player) : m_camera{camera}, world{20, 20, 1}, shader_player{"res/BasicNoColor.glsl"}, shader_consumable{"res/Consumable.glsl"}, physics{player}, player{player}
{
    shader_player.Use();
    shader_player.SetInt("texture1", 0);
    shader_consumable.Use();
    shader_consumable.SetInt("texture1", 0);
}

Coord RandomCell(int width, int height, bool center_at_zero = false)
{
    int x = (rand() % width);
    int y = (rand() % height);

    if (center_at_zero)
    {
        x -= width / 2;
        y -= height / 2;
    }

    return Coord{x, y};
}

Consumable *CreateFruit(Scene &scene, const Coord &coord, std::unordered_set<Coord, CoordHash> &occupied)
{
    Coord tex_cell_coord = RandomCell(8, 8, false);
    Consumable *fruit = new Consumable("Fruits", "tex/food_atlas.png", coord.x, coord.y, tex_cell_coord.x, tex_cell_coord.y);
    scene.AddGameObject(*fruit);
    scene.physics.collidables.push_back(new Collidable{fruit->pos, 1, 1, *fruit});

    occupied.insert(coord);
    return fruit;
}

void Scene::Setup()
{
    player.Setup(&world);

    for (size_t i = 0; i < 2; i++)
    {
        CreateFruit(*this, RandomCell(CELL_WIDTH, CELL_HEIGHT, true), occupied);
    }

    SignalManager::GetInstance()->itemEaten.connect_member(this, &Scene::HandleItemEaten);
}

void Scene::RenderGameObject(GameObject &obj, Shader &shader, float dt, float time)
{
    glm::mat4 parentModel = glm::mat4(1.0f);
    parentModel = glm::translate(parentModel, obj.pos);
    // Update all children of this object.
    for (unsigned int j = 0; j < obj.children.size(); j++)
    {
        GameObject *child = obj.children[j];
        child->Update(dt);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, child->pos);
        model = parentModel * model;

        glm::mat4 view = m_camera.GetView();
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(100.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
        // projection = glm::ortho(-20.0f, 20.0f, -15.0f, 15.0f, -2.9f, 10.0f);
        // projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -2.9f, 10.0f);

        shader.Use();
        shader.SetFloat("time", time);
        shader.SetInt("unique_id", obj.id);
        shader.SetMatrix4fv("model", model);
        shader.SetMatrix4fv("view", view);
        shader.SetMatrix4fv("projection", projection);

        child->Render();
    }
}

void Scene::HandleItemEaten()
{
    Coord coord = RandomCell(CELL_WIDTH, CELL_HEIGHT, true);
    while (occupied.count(coord))
    {
        coord = RandomCell(CELL_WIDTH, CELL_HEIGHT, true);
    }

    CreateFruit(*this, coord, occupied);
}

void Scene::Update(float dt)
{
    physics.Update(dt);

    player.Update(dt);

    // TODO: instead of regenerating occupied set every frame,
    // can just add new player head and remove player tail if player moved
    occupied.clear();
    for (Coord cell : player.GetCells())
    {
        occupied.insert(cell);
    }

    for (unsigned int i = 0; i < m_gameobjs.size(); i++)
    {
        GameObject &obj = m_gameobjs[i].get();
        if (obj.alive)
        {
            obj.Update(dt);
        }
    }

    for (size_t i = 0; i < physics.collisions.size(); i++)
    {
        player.RegisterCollision(&world, physics.collisions[i]);
    }
}

void Scene::Render(float dt, float time)
{
    for (unsigned int i = 0; i < m_gameobjs.size(); i++)
    {
        GameObject &obj = m_gameobjs[i].get();
        if (obj.alive)
        {
            RenderGameObject(obj, shader_consumable, dt, time);
        }
    }

    RenderGameObject(player, shader_player, dt, time);
}

void Scene::AddGameObject(GameObject &obj)
{
    obj.pos = world.GetWorldPos(obj.cell_pos);
    m_gameobjs.push_back(obj);
}