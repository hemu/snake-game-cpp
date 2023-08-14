#include "GameObject.h"
#include <string>
#include "Shader.h"
#include "Texture.h"

class Sprite : public GameObject
{
public:
    Sprite(std::string name, const std::string &texture_path, int tex_cell_x, int tex_cell_y, int tex_cell_w, int tex_cell_h);
    Sprite(std::string name, const std::string &texture_path);
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

    unsigned int m_indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
};
