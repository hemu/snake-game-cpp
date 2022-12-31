#pragma once

#include <GLFW/glfw3.h>
#include "Player.h"

namespace input
{
    void processInput(GLFWwindow *window, Player &player, float dt);
}