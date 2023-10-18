#include <string>
#include "Shader.h"
#include <map>

struct Character
{
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2 Size;        // Size of glyph
    glm::ivec2 Bearing;     // Offset from baseline to left/top of glyph
    unsigned int Advance;   // Offset to advance to next glyph
};

class Text
{
public:
    Text(std::string text);
    void Render(Shader &shader, float x, float y, float scale, glm::vec3 color);

private:
    int Setup();
    std::string text;
    unsigned int VAO;
    unsigned int VBO;
    std::map<char, Character> Characters;
};