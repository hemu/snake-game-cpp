#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"

class GameObject
{
public:
    GameObject();
    GameObject(const char *texture_path);
    glm::vec3 pos;
    Shader shader;
    Texture *texture{NULL};
    virtual void Render() = 0;
    virtual void Update(float dt){};

private:
};