#include "Consumable.h"
#include "Sprite.h"
#include <iostream>

Consumable::Consumable(std::string name, const std::string &texture_path, int cell_x, int cell_y) : GameObject(name, cell_x, cell_y)
{
    Sprite *sprite = new Sprite(name, texture_path);
    AddChild(sprite);
}

Consumable::~Consumable()
{
    std::cout << "Destroying " << name << "\n";
}