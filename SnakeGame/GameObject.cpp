#include "GameObject.h"
#include <iostream>

int GameObject::prevId{-1};

int GameObject::nextId()
{
    prevId++;
    return prevId;
}

GameObject::GameObject(std::string name) : pos{0.0f, 0.0f, 0.0f}, name{name}, cell_pos{Coord(0, 0)}
{
    id = GameObject::nextId();
}

GameObject::GameObject(std::string name, int cell_x, int cell_y) : pos{0.0f, 0.0f, 0.0f}, name{name}, cell_pos{Coord(cell_x, cell_y)}
{
    id = GameObject::nextId();
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