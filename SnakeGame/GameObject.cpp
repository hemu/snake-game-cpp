#include "GameObject.h"
#include <iostream>
#include "Shader.h"

GameObject::GameObject(std::string name) : pos{0.0f, 0.0f, 0.0f}, name{name}, cell_pos{Coord(0, 0)}
{
}

GameObject::GameObject(std::string name, const std::string &texture_path, int cell_x, int cell_y) : pos{0.0f, 0.0f, 0.0f}, name{name}, cell_pos{Coord(cell_x, cell_y)}
{
    texture = new Texture{texture_path.c_str()};
}

void GameObject::AddChild(GameObject *child)
{
    children.push_back(child);
}

GameObject::~GameObject()
{
    std::cout << "Gameobject destructor\n";
    if (texture != NULL)
    {
        delete texture;
    }
}