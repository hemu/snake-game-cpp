#include "Physics.h"
#include <iostream>

Physics::Physics(Player &player) : player{player} {}

void CheckAABB(Collidable a, Collidable b)
{
}

bool PlayerCollision(Player &player, Collidable *collidable)
{
    return glm::distance(player.pos, collidable->pos) < 1;
}

void Physics::Update(float dt)
{
    // Iterate through each collidable and see if there is an intersection.
    // Store each intersection in collisions array.
    collisions.clear();
    for (auto collidable : collidables)
    {
        if (PlayerCollision(player, collidable))
        {
            collidable->obj.alive = false;
        }
    }
}