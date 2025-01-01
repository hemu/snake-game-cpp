#include "Player.h"
#include "Sprite.h"
#include "World.h"
#include <iostream>
#include "SignalManager.h"

#define SNAKE_INIT_SEGMENT_COUNT 5

Player::Player() : GameObject("Snake")
{
}

void Player::Setup(World *world)
{
    m_world = world;
    pos = m_world->GetWorldPos(Coord{0, 0});
    std::string tex_path = "tex/snake2.png";
    for (int i = 0; i < SNAKE_INIT_SEGMENT_COUNT; i++)
    {
        Sprite *sprite = new Sprite("Snake", tex_path);
        AddChild(sprite);
        m_cells.push_back(Coord{0, -i});
        glm::vec3 newPos = m_world->GetWorldPos(m_cells[i]) - pos;
        children[i]->pos.x = newPos.x;
        children[i]->pos.y = newPos.y;
    }
}

void Player::RegisterCollision(World *world, Collidable *other)
{
    Sprite *sprite = new Sprite("Snake", "tex/snake2.png");
    AddChild(sprite);
    Coord last_cell = m_cells[m_cells.size() - 1];
    m_cells.push_back(Coord{last_cell.x, last_cell.y});
    SignalManager::GetInstance()->itemEaten.emit();
}

void Player::Update(float dt)
{
    if (m_world == NULL)
    {
        return;
    }
    non_grid_pos += dir * speed * dt;
    Coord next_head_cell = m_world->GetCellCoord(non_grid_pos.x, non_grid_pos.y);
    pos = m_world->GetWorldPos(next_head_cell);
    if (m_cells[0] != next_head_cell)
    {
        for (size_t i = children.size() - 1; i > 0; i--)
        {
            m_cells[i].x = m_cells[i - 1].x;
            m_cells[i].y = m_cells[i - 1].y;

            glm::vec3 newPos = m_world->GetWorldPos(m_cells[i]) - pos;
            children[i]->pos.x = newPos.x;
            children[i]->pos.y = newPos.y;
        }

        m_cells[0] = next_head_cell;
    }
}

const std::vector<Coord> &Player::GetCells()
{
    return m_cells;
}

void Player::SetDir(glm::vec3 _dir)
{
    dir = _dir;
}

Player::~Player()
{
    for (size_t i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
}