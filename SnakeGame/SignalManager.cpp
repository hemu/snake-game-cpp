#include "SignalManager.h"

SignalManager *SignalManager::m_instance = nullptr;

SignalManager *SignalManager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new SignalManager();
    }

    return m_instance;
}

SignalManager::SignalManager()
{
}