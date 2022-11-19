#pragma once
#include <GLFW/glfw3.h>

class Mouse
{
public:
    Mouse(GLFWwindow *window, Camera *camera);
    void Setup();
    void ProcessInput();

    Camera *camera;
    GLFWwindow *window;

private:
    float last_x = 400.0f;
    float last_y = 300.0f;
    float yaw = 0.0f;
    float pitch = 0.0f;
};
