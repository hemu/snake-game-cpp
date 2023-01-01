#include "GameObject.h"

GameObject::GameObject() : pos{0.0f, 0.0f, 0.0f}, shader{"res/BasicNoColor.shader"}
{
}

GameObject::GameObject(const char *texture_path) : shader{"res/BasicNoColor.shader"}, pos{0.0f, 0.0f, 0.0f}
{
    texture = new Texture{texture_path};
}

void GameObject::AddChild(GameObject *child)
{
    children.push_back(child);
}
