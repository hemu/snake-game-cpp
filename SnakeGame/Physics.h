#include <vector>
#include "GameObject.h"
#include "glm/glm.hpp"
#include "Player.h"

class Collidable
{
public:
    glm::vec3 pos;
    float width;
    float height;
    GameObject &obj;
};

class Collision
{
public:
    Collidable a;
    Collidable b;
};

class Physics
{
public:
    Physics(Player &player);
    std::vector<Collidable *> collidables;
    std::vector<Collision> collisions;
    Player &player;

    void Update(float dt);
};