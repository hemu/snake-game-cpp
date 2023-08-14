#include <string>
#include "Texture.h"
#include <map>

class Atlas
{
public:
    static Atlas *GetInstance();
    Texture *GetTexture(const std::string name);

protected:
    Atlas();

    static Atlas *m_instance;

private:
    std::map<std::string, Texture *> m_textures;
};