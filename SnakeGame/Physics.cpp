#include "Physics.h"

Physics::Physics(Player &player) : player{player} {}

void CheckCollision(Collidable a, Collidable b)
{
}

void Physics::Update(float dt)
{
    // Iterate through each collidable and see if there is an intersection.
    // Store each intersection in collisions array.
    collisions.clear();
    // for (auto collidable: collidables) {

    // }
}