#include "Input.h"

namespace input
{
    void processInput(GLFWwindow *window, Camera *camera, float dt)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera->pos += camera->speed * dt * camera->front;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera->pos -= camera->speed * dt * camera->front;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera->pos -= glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed * dt;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera->pos += glm::normalize(glm::cross(camera->front, camera->up)) * camera->speed * dt;
    }
}