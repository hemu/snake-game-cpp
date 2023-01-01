#include "Input.h"
#include "Player.h"
#include <glm/glm.hpp>

namespace input
{
    void processInput(GLFWwindow *window, Player &player, float dt)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            player.SetDir(glm::vec3(0.0f, 1.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            player.SetDir(glm::vec3(0.0f, -1.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            player.SetDir(glm::vec3(-1.0f, 0.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            player.SetDir(glm::vec3(1.0f, 0.0f, 0.0f));
    }
}