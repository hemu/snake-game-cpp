#pragma once
#include "GameObject.h"
#include <string>
#include "Shader.h"

class Sprite : public GameObject
{
public:
    Sprite(std::string name, const std::string &texture_path);
    ~Sprite();

    void Setup();
    void Render() override;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    float m_vertices[20] = {
        // positions          // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
    };
    unsigned int m_indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
};