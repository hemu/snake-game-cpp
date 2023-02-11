#include "Physics.h"
#include <iostream>

Physics::Physics(Player &player) : player{player} {}

bool CheckAABB(Collidable *a, Collidable *b)
{
    // is A to right of B?
    // is A to left of B?
    // is A above B?
    // is A below B?
    bool A_right_of_B = a->pos.x - a->width / 2.0f > b->pos.x + b->width / 2.0f;
    bool A_left_of_B = a->pos.x + a->width / 2.0f < b->pos.x - b->width / 2.0f;
    bool A_above_B = a->pos.y - a->height / 2.0f > b->pos.y + b->height / 2.0f;
    bool A_below_B = a->pos.y + a->height / 2.0f < b->pos.y - b->height / 2.0f;

    return !A_right_of_B && !A_left_of_B && !A_above_B && !A_below_B;
}

bool PlayerCollision(Player &player, Collidable *collidable)
{
    // return glm::distance(player.pos, collidable->pos) < 1;
    Collidable player_collidable = Collidable{player.pos, player.head_width, player.head_height, player};
    return CheckAABB(&player_collidable, collidable);
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