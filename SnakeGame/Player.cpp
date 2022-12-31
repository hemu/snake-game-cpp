#include "Player.h"

Player::Player() : GameObject(), m_cube{}
{
}

void Player::Render()
{
    m_cube.Render();
}