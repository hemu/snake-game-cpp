#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
#include <vector>
#include "World.h"
#include "Collidable.h"

class Player : public GameObject
{
public:
    Player();
    ~Player();
    void Setup(World *world);
    void Update(float dt) override;
    const float speed{8.0f};
    glm::vec3 next_dir{0.0f, 1.0f, 0.0f};
    void SetDir(glm::vec3 dir);
    World *m_world;
    float head_width{1.0f};
    float head_height{1.0f};
    void RegisterCollision(World *world, Collidable *a);

private:
    glm::vec3 dir{0.0f, 1.0f, 0.0f};
    glm::vec3 non_grid_pos{0.0, 0.0, 0.0};
    std::vector<Coord> m_cells;

    void HandleItemEaten();
};