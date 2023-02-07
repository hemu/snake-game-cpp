#pragma once
#include "Camera.h"
#include <vector>
#include "GameObject.h"
#include "Texture.h"
#include "World.h"
#include "Shader.h"
#include "Physics.h"

class Scene
{
public:
    Scene(Camera &camera, Player &player);
    void Render(float dt);
    void AddGameObject(GameObject &gameobject);
    World world;

private:
    Camera &m_camera;
    std::vector<std::reference_wrapper<GameObject>> m_gameobjs;
    Shader shader;
    Physics physics;
    Player &player;
    void RenderGameObject(GameObject &obj, float dt);
};