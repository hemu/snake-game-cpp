#include "GameObject.h"
#include <iostream>

GameObject::GameObject() : shader{"res/BasicNoColor.shader"}, pos{0.0f, 0.0f, 0.0f}, name{"Default"} {}

GameObject::GameObject(std::string name) : shader{"res/BasicNoColor.shader"}, pos{0.0f, 0.0f, 0.0f}, name{name}
{
}

GameObject::GameObject(const std::string &texture_path, std::string name) : shader{"res/BasicNoColor.shader"}, pos{0.0f, 0.0f, 0.0f}, name{name}
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