#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
#include <vector>
#include "World.h"

class Player : public GameObject
{
public:
    Player(World &world);
    ~Player();
    void Update(float dt) override;
    const float speed{3.0f};
    glm::vec3 next_dir{0.0f, 1.0f, 0.0f};
    void SetDir(glm::vec3 dir);

private:
    glm::vec3 dir{0.0f, 1.0f, 0.0f};
    glm::vec3 non_grid_pos{0.0, 0.0, 0.0};
    std::vector<Coord> m_cells;
    World &m_world;
};