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
    void Render(float dt, float time);
    void AddGameObject(GameObject &gameobject);
    void Update(float dt);
    void Setup();
    World world;
    Physics physics;

private:
    Camera &m_camera;
    std::vector<std::reference_wrapper<GameObject>> m_gameobjs;
    Shader shader_player;
    Shader shader_consumable;
    Player &player;
    void RenderGameObject(GameObject &obj, Shader &shader, float dt, float time);
    void HandleItemEaten();
};