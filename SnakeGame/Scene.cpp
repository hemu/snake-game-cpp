#include "Scene.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include "World.h"
#include "Player.h"
#include <set>

Scene::Scene(Camera &camera, Player &player) : m_camera{camera}, world{20, 20, 1}, shader_player{"res/BasicNoColor.glsl"}, shader_consumable{"res/Consumable.glsl"}, physics{player}, player{player}
{
    shader_player.Use();
    shader_player.SetInt("texture1", 0);
    shader_consumable.Use();
    shader_consumable.SetInt("texture1", 0);
}

void Scene::Setup()
{
    for (size_t i = 0; i < m_gameobjs.size(); i++)
    {
        GameObject &obj = m_gameobjs[i].get();
        obj.pos = world.GetWorldPos(obj.cell_pos);
    }
}

void Scene::RenderGameObject(GameObject &obj, Shader &shader, float dt, float time)
{
    obj.Update(dt);
    glm::mat4 parentModel = glm::mat4(1.0f);
    parentModel = glm::translate(parentModel, obj.pos);
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

void Scene::Update(float dt)
{
    physics.Update(dt);

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

void Scene::AddGameObject(GameObject &gameobj)
{
    m_gameobjs.push_back(gameobj);
}