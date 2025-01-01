#pragma once
#include <glm/glm.hpp>
#include <functional>

class Coord
{
public:
    Coord() : x(0), y(0){};
    Coord(int x, int y) : x(x), y(y){};
    bool operator==(const Coord &other) const;
    bool operator!=(const Coord &other) const;
    Coord operator-(const Coord &other) const;
    Coord operator+(const Coord &other) const;

    int x;
    int y;
};

struct CoordHash
{
    std::hash<int> int_hash;

    std::size_t operator()(const Coord &coord) const
    {
        return (59 + int_hash(coord.x)) * 59 + int_hash(coord.y);
    }
};

class World
{
public:
    World(int cell_width, int cell_height, float cell_size);
    Coord GetCellCoord(float x, float y);
    glm::vec3 GetWorldPos(const Coord &coord);

private:
    int m_cell_width;
    int m_cell_height;
    float m_cell_size;
    float m_cell_size_half;
};
