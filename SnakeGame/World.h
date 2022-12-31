#pragma once

class Coord
{
public:
    Coord(int x, int y) : x(x), y(y){};
    bool operator==(const Coord &other) const;
    bool operator!=(const Coord &other) const;

    int x;
    int y;
};

class World
{
public:
    World(int width, int height, int cell_size) : m_width(width), m_height(height), m_cell_size(cell_size){};
    Coord GetCellCoord(float x, float y);

private:
    int m_width;
    int m_height;
    int m_cell_size;
};
