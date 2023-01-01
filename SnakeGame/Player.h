#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
#include "Cube.h"
#include <vector>
#include "World.h"

class Player : public GameObject
{
public:
    Player(World &world);
    void Update(float dt) override;
    const float speed{8.0f};
    glm::vec3 next_dir{0.0f, 1.0f, 0.0f};
    void SetDir(glm::vec3 dir);

private:
    glm::vec3 dir{0.0f, 1.0f, 0.0f};
    glm::vec3 m_pos{0.0f, 0.0f, 0.0f};
    std::vector<Coord> m_cell_pos;
    World &m_world;
};