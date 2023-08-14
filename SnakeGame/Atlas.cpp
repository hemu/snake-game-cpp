#include "Atlas.h"

Atlas *Atlas::m_instance = nullptr;

Atlas *Atlas::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Atlas();
    }

    return m_instance;
}

Atlas::Atlas()
{
    m_textures = std::map<std::string, Texture *>();
}

Texture *Atlas::GetTexture(const std::string path)
{
    if (m_textures.find(path) == m_textures.end())
    {
        m_textures[path] = new Texture(path.c_str());
    }

    return m_textures[path];
}