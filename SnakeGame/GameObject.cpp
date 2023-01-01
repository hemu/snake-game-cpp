#include "GameObject.h"

GameObject::GameObject() : shader{"res/BasicNoColor.shader"}, pos{0.0f, 0.0f, 0.0f}
{
}

GameObject::GameObject(const char *texture_path) : shader{"res/BasicNoColor.shader"}, pos{0.0f, 0.0f, 0.0f}
{
    texture = new Texture{texture_path};
}
