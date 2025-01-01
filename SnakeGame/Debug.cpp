#include <stdexcept>
#include "Debug.h"
#include <iostream>

std::array<Line, MAX_CELL_DIM * MAX_CELL_DIM + 2> getGridLines(int cell_count_x, int cell_count_y, float cell_size) {
    if (cell_count_x > MAX_CELL_DIM || cell_count_y > MAX_CELL_DIM) {
        throw std::runtime_error("Cell count must be less than 20");
    }

    const glm::vec3 line_color = glm::vec3(0.2f, 0.2f, 0.2f);

    std::array<Line, MAX_CELL_DIM * MAX_CELL_DIM + 2> lines;

    float offset_x = (cell_size * cell_count_x) / 2.0f;
    float offset_y = (cell_size * cell_count_y) / 2.0f;

    for (int i = 0; i <= cell_count_x; i++) {
        lines[i] = Line(glm::vec3(i * cell_size - offset_x, -offset_y, 0.0f), glm::vec3(i * cell_size - offset_x, cell_size * cell_count_y - offset_y, 0.0f), line_color);
    }
    for (int j = 0; j <= cell_count_y; j++) {
        lines[cell_count_x + 1 + j] = Line(glm::vec3(-offset_x, j * cell_size - offset_y, 0.0f), glm::vec3(cell_size * cell_count_x - offset_x, j * cell_size - offset_y, 0.0f), line_color);
    }

    return lines;
}

