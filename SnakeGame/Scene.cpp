#include "Scene.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

Scene::Scene(Camera &camera) : m_camera{camera}, m_texture{"container.jpg"}
{
}

void Scene::Render()
{
    for (unsigned int i = 0; i < m_gameobjs.size(); i++)
    {
        GameObject &obj{m_gameobjs[i].get()};
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, obj.pos);

        // model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.5f));
        unsigned int modelLoc = glGetUniformLocation(obj.shader.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        glm::mat4 view = m_camera.GetView();
        unsigned int viewLoc = glGetUniformLocation(obj.shader.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(100.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        unsigned int projectionLoc = glGetUniformLocation(obj.shader.ID, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_texture.m_ID);

        obj.shader.Use();
        obj.Render();
    }
}

void Scene::AddGameObject(GameObject &gameobj)
{
    m_gameobjs.push_back(gameobj);
    gameobj.shader.Use();
    gameobj.shader.SetInt("texture1", 0);
}