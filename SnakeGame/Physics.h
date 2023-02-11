#pragma once
#include <vector>
#include "GameObject.h"
#include "glm/glm.hpp"
#include "Player.h"
#include "Collidable.h"

class Physics
{
public:
    Physics(Player &player);
    std::vector<Collidable *> collidables;
    std::vector<Collidable *> collisions;
    Player &player;

    void Update(float dt);
};