#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
#include "Cube.h"
#include <vector>

class Player : public GameObject
{
public:
    Player();
    void Update(float dt) override;
    const float speed{1.0f};
    glm::vec3 dir{0.0f, 1.0f, 0.0f};

private:
};