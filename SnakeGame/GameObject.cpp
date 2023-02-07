#include "GameObject.h"
#include <iostream>
#include "Shader.h"

GameObject::GameObject(std::string name) : pos{0.0f, 0.0f, 0.0f}, name{name}
{
}

GameObject::GameObject(std::string name, const std::string &texture_path) : pos{0.0f, 0.0f, 0.0f}, name{name}
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