#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include <vector>
#include <string>

class GameObject
{
public:
    GameObject(std::string name);
    GameObject(std::string name, const std::string &texture_path);
    ~GameObject();
    glm::vec3 pos;
    Texture *texture{NULL};
    std::vector<GameObject *> children{};
    std::string name;

    void AddChild(GameObject *child);

    virtual void Render(){};
    virtual void Update(float dt){};

private:
};