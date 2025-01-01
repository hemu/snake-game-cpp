#include "Physics.h"
#include <iostream>

Physics::Physics(Player &player) : player{player} {}

bool CheckAABB(Collidable *a, Collidable *b)
{
    bool A_right_of_B = a->pos.x - a->width / 2.0f > b->pos.x + b->width / 2.0f;
    bool A_left_of_B = a->pos.x + a->width / 2.0f < b->pos.x - b->width / 2.0f;
    bool A_above_B = a->pos.y - a->height / 2.0f > b->pos.y + b->height / 2.0f;
    bool A_below_B = a->pos.y + a->height / 2.0f < b->pos.y - b->height / 2.0f;

    return !A_right_of_B && !A_left_of_B && !A_above_B && !A_below_B;
}

bool PlayerCollision(Player &player, Collidable *collidable)
{
    Collidable player_collidable = Collidable{player.pos, player.head_width * 0.9f, player.head_height * 0.8f, player};
    return CheckAABB(&player_collidable, collidable);
}

void Physics::Update(float dt)
{
    collisions.clear();
    for (Collidable *collidable : collidables)
    {
        if (!collidable->obj.alive)
        {
            continue;
        }
        if (PlayerCollision(player, collidable))
        {
            collidable->obj.alive = false;
            collisions.push_back(collidable);
        }
    }
}