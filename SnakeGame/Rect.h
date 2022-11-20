#pragma once

class Rect
{
public:
    Rect();
    ~Rect();
    void setup();
    void teardown();
    void update();
    void render();

    float m_vertices[32] = {
        // positions          // colors           // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
    };

    unsigned int m_indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    float m_texCoords[6] = {
        0.0f, 0.0f, // lower-left
        1.0, 0.0f,  // lower-right
        0.5f, 1.0f  // top-center
    };

    unsigned int VAO;
    unsigned int EBO;
    unsigned int VBO;

private:
};
