#pragma once

#include <GLFW/glfw3.h>
#include "Camera.h"

namespace input
{
    void processInput(GLFWwindow *window, Camera *camera);
}