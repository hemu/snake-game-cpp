#include "World.h"
#include <cmath>
#include <glm/glm.hpp>

const float CELL_EPSILON = 0.0001f;

glm::vec3 World::GetWorldPos(Coord coord)
{
    return glm::vec3(coord.x * m_cell_size, coord.y * m_cell_size, 0.0f);
}

Coord World::GetCellCoord(float x, float y)
{
    int sign_x = x < 0 ? -1 : 1;
    int sign_y = y < 0 ? -1 : 1;
    x = std::abs(x);
    y = std::abs(y);
    float x_cell = (int)x / m_cell_size;
    float remain_x = x - x_cell * m_cell_size;
    if (remain_x + CELL_EPSILON >= m_cell_size / 2.0f)
    {
        x_cell += 1;
    }

    float y_cell = (int)y / m_cell_size;
    float remain_y = y - y_cell * m_cell_size;
    if (remain_y + CELL_EPSILON >= m_cell_size / 2.0f)
    {
        y_cell += 1;
    }

    return Coord((int)(x_cell * sign_x), (int)(y_cell * sign_y));
}

bool Coord::operator==(const Coord &other) const
{
    return x == other.x && y == other.y;
}

bool Coord::operator!=(const Coord &other) const
{
    return !(*this == other);
}