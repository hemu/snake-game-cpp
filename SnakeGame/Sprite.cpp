#include "Sprite.h"
#include <glad/glad.h>
#include <iostream>

Sprite::Sprite(std::string name, const std::string &texture_path, int tex_cell_x, int tex_cell_y) : GameObject(name, 0, 0), texture{new Texture(texture_path.c_str())}
{
    // TODO: create a separate SpriteSheet class that handles cells, make Sprite take in all tex coords
    float sprite_w = 1.0f / 8.0f;
    float sprite_h = 1.0f / 8.0f;
    m_vertices[3] = tex_cell_x * sprite_w + sprite_w;
    m_vertices[4] = 1.0f - tex_cell_y * sprite_h;
    m_vertices[8] = tex_cell_x * sprite_w + sprite_w;
    m_vertices[9] = 1.0f - (tex_cell_y * sprite_h + sprite_h);
    m_vertices[13] = tex_cell_x * sprite_w;
    m_vertices[14] = 1.0f - (tex_cell_y * sprite_h + sprite_h);
    m_vertices[18] = tex_cell_x * sprite_w;
    m_vertices[19] = 1.0f - tex_cell_y * sprite_h;
    Setup();
}

Sprite::Sprite(std::string name, const std::string &texture_path) : Sprite(name, texture_path, 0, 0)
{
}

void Sprite::Setup()
{
    // Bind a vertex array. The following VBO, EBO, and attribute pointers calls
    // are all needed *every time* we want to render this sprite. The vertex array
    // acts as a container for us to save all of these calls so that in the future,
    // we can just bind the vertex array instead of calling all of these functions again.
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

    // Element buffers allow you to define smaller set of vertices and define a polygon
    // by specifying indices of the vertices to use. So that vertices shared by multiple
    // polygons only need to be defined once. Example: for a rectangle (2 triangles), only
    // 4 vertices need to be defined in VBO, and the two triangles can be defined by 6 indices
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

    // First attribute defined in shader, specified by this line in shader:
    // layout (location = 0) in vec3 aPos;
    // This attribute represents raw vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Second attribute defined in shader, specified by this line in shader:
    // layout (location = 1) in vec2 aTexCoord;
    // Represents texture coords
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // Unbind vertex array
    glBindVertexArray(0);
}

void Sprite::Render()
{
    if (texture != NULL)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->m_ID);
    }
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Sprite::~Sprite()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    delete texture;
}