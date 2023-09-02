#pragma once
#include "glm/glm.hpp"
#include "Signal.h"

class SignalManager
{

public:
    static SignalManager *GetInstance();
    Signal<> itemEaten;

protected:
    SignalManager();

    static SignalManager *m_instance;
};