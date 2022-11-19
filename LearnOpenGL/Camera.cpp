#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 _pos, glm::vec3 _up, glm::vec3 _front)
{
    pos = _pos;
    up = _up;
    front = _front;
}

glm::mat4 Camera::GetView()
{
    return glm::lookAt(pos, pos + front, up);
}

glm::mat4 Camera::LookAt(glm::vec3 target)
{
    return glm::lookAt(pos, target, up);
}