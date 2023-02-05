#include "Scene.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include "World.h"
#include <set>

Scene::Scene(Camera &camera) : m_camera{camera}, world{20, 20, 1}
{
}

void Scene::Render(float dt)
{
    for (unsigned int i = 0; i < m_gameobjs.size(); i++)
    {
        GameObject &obj = m_gameobjs[i].get();
        obj.Update(dt);

        glm::mat4 parentModel = glm::mat4(1.0f);
        parentModel = glm::translate(parentModel, obj.pos);
        for (unsigned int j = 0; j < obj.children.size(); j++)
        {
            GameObject *child = obj.children[j];
            child->Update(dt);
            std::cout << "Rendering: " << child->name << "\n";

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, child->pos);
            model = parentModel * model;

            glm::mat4 view = m_camera.GetView();
            glm::mat4 projection = glm::mat4(1.0f);
            projection = glm::perspective(glm::radians(100.0f), 800.0f / 600.0f, 0.1f, 100.0f);
            // projection = glm::ortho(-20.0f, 20.0f, -15.0f, 15.0f, -2.9f, 10.0f);
            // projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -2.9f, 10.0f);

            child->shader.SetMatrix4fv("model", model);
            child->shader.SetMatrix4fv("view", view);
            child->shader.SetMatrix4fv("projection", projection);

            child->Render();
        }
    }
}

void Scene::AddGameObject(GameObject &gameobj)
{
    m_gameobjs.push_back(gameobj);
}