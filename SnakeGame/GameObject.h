#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include <vector>
#include <string>

class GameObject
{
public:
    GameObject();
    GameObject(std::string name);
    GameObject(const std::string &texture_path, std::string name);
    ~GameObject();
    glm::vec3 pos;
    Shader shader;
    Texture *texture{NULL};
    std::vector<GameObject *> children{};
    std::string name;

    void AddChild(GameObject *child);

    virtual void Render(){};
    virtual void Update(float dt){};

private:
};