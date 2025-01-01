#pragma once

#include "Line.h"
#include "World.h"
#include "glad/glad.h"
#include <array>

#define MAX_CELL_DIM 40

std::array<Line, MAX_CELL_DIM * MAX_CELL_DIM + 2> getGridLines(int cell_count_x, int cell_count_y, float cell_size);
