#pragma once
#include <glm/glm.hpp>
#include "Shader.h"

class GameObject
{
public:
    GameObject();
    glm::vec3 pos;
    Shader shader;
    virtual void Render() = 0;

private:
};