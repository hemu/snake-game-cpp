#include "Consumable.h"
#include "Sprite.h"

Consumable::Consumable(const std::string &texture_path, std::string name) : GameObject(texture_path, name)
{
    Sprite *sprite = new Sprite(texture_path, name);
    AddChild(sprite);
}