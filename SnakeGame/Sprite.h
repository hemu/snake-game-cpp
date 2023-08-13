#pragma once
#include "GameObject.h"
#include <string>
#include "Shader.h"
#include "Texture.h"

class Sprite : public GameObject
{
public:
    Sprite(std::string name, const std::string &texture_path);
    Sprite(std::string name, const std::string &texture_path, int tex_cell_x, int tex_cell_y);
    ~Sprite();

    void Setup();
    void Render() override;

    Texture *texture;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    float m_vertices[20] = {
        // positions      // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
    };
    // float sprite_w = 1.0f / 8.0f;
    // float sprite_h = 1.0f / 8.0f;
    // float sprite_i = 0;
    // float m_vertices[20] = {
    //     // positions      // texture coords
    //     0.5f, 0.5f, 0.0f, sprite_i *sprite_w + sprite_w, 1.0f - sprite_i *sprite_h,                // top right
    //     0.5f, -0.5f, 0.0f, sprite_i *sprite_w + sprite_w, 1.0f - (sprite_i * sprite_h + sprite_h), // bottom right
    //     -0.5f, -0.5f, 0.0f, sprite_i *sprite_w, 1.0f - (sprite_i * sprite_h + sprite_h),           // bottom left
    //     -0.5f, 0.5f, 0.0f, sprite_i *sprite_w, 1.0f - sprite_i *sprite_h                           // top left
    // };
    unsigned int m_indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
};