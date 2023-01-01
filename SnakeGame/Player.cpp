#include "Player.h"
#include "Cube.h"

Player::Player() : GameObject("tex/snake.jpg")
{
    for (int i = 0; i < 5; i++)
    {
        Cube *cube = new Cube();
        cube->pos.y = i * -1.0f;
        AddChild(cube);
    }
}

void Player::Update(float dt)
{
    for (auto child : children)
    {
        child->pos += dir * speed * dt;
    }
}
