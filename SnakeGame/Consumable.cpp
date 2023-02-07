#include "Consumable.h"
#include "Sprite.h"

Consumable::Consumable(std::string name, const std::string &texture_path) : GameObject(name, texture_path)
{
    Sprite *sprite = new Sprite(name, texture_path);
    AddChild(sprite);
}