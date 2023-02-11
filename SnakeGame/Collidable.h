#pragma once
#include "GameObject.h"
#include "glm/glm.hpp"

class Collidable
{
public:
    glm::vec3 pos;
    float width;
    float height;
    GameObject &obj;
};
