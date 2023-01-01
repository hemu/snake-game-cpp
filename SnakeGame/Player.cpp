#include "Player.h"

Player::Player() : GameObject("tex/snake.jpg"), m_cube{}
{
}

void Player::Update(float dt)
{
    pos += dir * speed * dt;
}

void Player::Render()
{
    m_cube.Render();
}
