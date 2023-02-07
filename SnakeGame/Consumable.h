#include <string>
#include "GameObject.h"
#include <string>

class Consumable : public GameObject
{
public:
    Consumable(std::string name, const std::string &texture_path);
};