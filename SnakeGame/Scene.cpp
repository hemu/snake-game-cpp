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
        GameObject &obj{m_gameobjs[i].get()};
        obj.Update(dt);

        glm::mat4 parentModel = glm::mat4(1.0f);
        parentModel = glm::translate(parentModel, obj.pos);
        for (unsigned int j = 0; j < obj.children.size(); j++)
        {
            GameObject *child{obj.children[j]};
            child->Update(dt);

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, child->pos);
            model = parentModel * model;

            // model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));

            // model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.5f));
            unsigned int modelLoc = glGetUniformLocation(obj.shader.ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glm::mat4 view = m_camera.GetView();
            unsigned int viewLoc = glGetUniformLocation(obj.shader.ID, "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

            glm::mat4 projection = glm::mat4(1.0f);
            projection = glm::perspective(glm::radians(100.0f), 800.0f / 600.0f, 0.1f, 100.0f);
            // projection = glm::ortho(-20.0f, 20.0f, -15.0f, 15.0f, -2.9f, 10.0f);
            // projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -2.9f, 10.0f);
            unsigned int projectionLoc = glGetUniformLocation(obj.shader.ID, "projection");
            glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

            if (child->texture != NULL)
            {
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, child->texture->m_ID);
            }

            obj.shader.Use();
            child->Render();
        }
    }
}

void Scene::AddGameObject(GameObject &gameobj)
{
    m_gameobjs.push_back(gameobj);
    gameobj.shader.Use();
    gameobj.shader.SetInt("texture1", 0);
}