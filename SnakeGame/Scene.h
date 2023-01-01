#pragma once
#include "Camera.h"
#include <vector>
#include "GameObject.h"
#include "Texture.h"
#include "World.h"

class Scene
{
public:
    Scene(Camera &camera);
    void Render(float dt);
    void AddGameObject(GameObject &gameobject);

private:
    Camera &m_camera;
    std::vector<std::reference_wrapper<GameObject>> m_gameobjs;
    Texture m_texture;
    World m_world;
};