#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
#include "Cube.h"

class Player : public GameObject
{
public:
    Player();
    void Render() override;
    void Update(float dt) override;
    const float speed{5.0f};
    glm::vec3 dir{0.0f, 1.0f, 0.0f};

private:
    Cube m_cube;
};