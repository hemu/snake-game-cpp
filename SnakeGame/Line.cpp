#include <glad/glad.h>

#include "Line.h"

Line::Line() : start{0, 0, 0}, end{0, 0, 0}, color{1, 1, 1} {}

Line::Line(glm::vec3 start, glm::vec3 end, glm::vec3 color) : start{start}, end{end}, color{color} {
    float vertices[12] = {
        start.x, start.y, start.z, color.x, color.y, color.z,
        end.x, end.y, end.z, color.x, color.y, color.z
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Line::Render() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
}
