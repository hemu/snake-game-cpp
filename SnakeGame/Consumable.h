#include <string>
#include "GameObject.h"
#include <string>

class Consumable : public GameObject
{
public:
    Consumable(std::string name, const std::string &texture_path, int cell_x, int cell_y);
};