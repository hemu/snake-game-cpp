#pragma once
#include <glm/glm.hpp>

class Line {
public: 
    Line(glm::vec3 start, glm::vec3 end, glm::vec3 color);

    unsigned int VAO, VBO;
    glm::vec3 start;
    glm::vec3 end;
    glm::vec3 color;

    void Render(); 
};