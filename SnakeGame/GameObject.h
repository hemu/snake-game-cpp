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
    GameObject(std::string name, int cell_x, int cell_y);
    static int nextId();
    ~GameObject();
    glm::vec3 pos;
    Coord cell_pos;
    Texture *texture{NULL};
    std::vector<GameObject *> children{};
    std::string name;
    bool alive = true;
    int id;

    void AddChild(GameObject *child);

    virtual void Render(){};
    virtual void Update(float dt){};

private:
    static int prevId;
};