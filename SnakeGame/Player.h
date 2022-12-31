#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
#include "Cube.h"

class Player : public GameObject
{
public:
    Player();
    void Render() override;

private:
    Cube m_cube;
};