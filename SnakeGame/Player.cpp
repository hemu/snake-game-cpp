#include "Player.h"
#include "Cube.h"
#include "World.h"

Player::Player(World &world) : GameObject("tex/snake.jpg"), m_world(world)
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
    Coord cur_head_coord = m_world.GetCellCoord(m_pos.x, m_pos.y);
    m_pos += dir * speed * dt;
    Coord next_head_coord = m_world.GetCellCoord(m_pos.x, m_pos.y);

    if (cur_head_coord != next_head_coord)
    {
        for (int i = children.size() - 1; i > 0; i--)
        {
            children[i]->pos.x = children[i - 1]->pos.x;
            children[i]->pos.y = children[i - 1]->pos.y;
            children[i]->pos.z = children[i - 1]->pos.z;
        }
    }

    glm::vec3 next_head_pos = m_world.GetWorldPos(next_head_coord);

    children[0]->pos = next_head_pos;
}

void Player::SetDir(glm::vec3 _dir)
{
    dir = _dir;
}