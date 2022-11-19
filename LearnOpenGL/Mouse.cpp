#include "Camera.h"
#include "Mouse.h"
#include <GLFW/glfw3.h>
#include <iostream>

Mouse::Mouse(GLFWwindow *_window, Camera *_camera)
{
    camera = _camera;
    window = _window;
}

void Mouse::ProcessInput()
{
    GLdouble pos_x, pos_y;
    glfwGetCursorPos(window, &pos_x, &pos_y);
    float offset_x = pos_x - last_x;
    float offset_y = pos_y - last_y;

    const float sensitivity = 0.1f;
    offset_x *= sensitivity;
    offset_y *= sensitivity;

    yaw += offset_x;
    pitch += offset_y;

    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camera->front = glm::normalize(direction);

    last_x = pos_x;
    last_y = pos_y;
}

void Mouse::Setup()
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
