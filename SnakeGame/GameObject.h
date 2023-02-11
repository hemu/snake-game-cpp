#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include <vector>
#include <string>
#include "World.h"

class GameObject
{
public:
    GameObject(std::string name);
    GameObject(std::string name, const std::string &texture_path, int cell_x, int cell_y);
    ~GameObject();
    glm::vec3 pos;
    Coord cell_pos;
    Texture *texture{NULL};
    std::vector<GameObject *> children{};
    std::string name;
    bool alive = true;

    void AddChild(GameObject *child);

    virtual void Render(){};
    virtual void Update(float dt){};

private:
};