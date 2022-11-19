#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(glm::vec3 pos, glm::vec3 up, glm::vec3 front);
    glm::vec3 pos{glm::vec3(0.0f, 0.0f, 0.0f)};
    glm::vec3 up{glm::vec3(0.0f, 1.0f, 0.0f)};
    glm::vec3 front{glm::vec3(0.0f, 0.0f, -1.0f)};
    float speed = 0.02f;

    glm::mat4 GetView();
    glm::mat4 LookAt(glm::vec3 target);
};
