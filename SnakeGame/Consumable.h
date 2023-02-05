#include <string>
#include "GameObject.h"
#include <string>

class Consumable : public GameObject
{
public:
    Consumable(const std::string &texture_path, std::string name);
};