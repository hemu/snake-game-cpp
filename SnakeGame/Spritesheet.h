#pragma once
#include <string>
#include "Texture.h"
#include "Shader.h"

class Spritesheet
{
public:
    Spritesheet(std::string &texture_path, float item_width, float item_height);
    ~Spritesheet();

    void Setup();
    void Render(Shader &shader, float item_row, float item_col);

    Texture *texture;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    float m_vertices[20] = {
        // positions
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f,  // top left
    };
    unsigned int m_indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

private:
    Texture *texture;
};
