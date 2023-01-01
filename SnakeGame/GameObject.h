#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include <vector>

class GameObject
{
public:
    GameObject();
    GameObject(const char *texture_path);
    glm::vec3 pos;
    Shader shader;
    Texture *texture{NULL};
    std::vector<GameObject *> children{};

    void AddChild(GameObject *child);

    virtual void Render(){};
    virtual void Update(float dt){};

private:
};