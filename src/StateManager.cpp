#include "StateManager.hpp"

//STD
#include <assert.h>
#include <iostream>
#include <memory>

//SELF
#include "GameState.hpp"
#include "MenuState.hpp"

namespace zge
{

std::unique_ptr<StateManager> StateManager::m_Instance;

StateManager::StateManager()
{
    m_ActiveStatePosition = 0;
}

StateManager::~StateManager()
{
    std::cout << "[StateManager] Destructor\n";
}

StateManager& StateManager::getInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = std::unique_ptr<StateManager>(new StateManager);
    }

    return *m_Instance.get();
}

void StateManager::deleteInstance()
{
    m_Instance.reset(nullptr);
}

void StateManager::addState(StateID s)
{
    for (unsigned int i = 0; i < m_States.size(); ++i) //Use bitmasks in the future.
    {
        if (m_States[i]->stateID == s)
        {
            assert(!"Failed to add State, State already exists.");
        }
    }

    switch(s)
    {
    case StateID::MenuState:
    {
        //::MenuState ms;
        std::shared_ptr<State> ms(new ::MenuState);
        m_States.push_back(ms);
        std::cout << "MenuState Added\n";
        break;
    }
    case StateID::GameState:
    {
        //::GameState gs;
        std::shared_ptr<State> gs(new ::GameState);
        m_States.push_back(gs);
        std::cout << "GameState Added\n";
        break;
    }
    default:
        assert(!"Requested State does not exist.");
    }
}

void StateManager::changeState(StateID s)
{
    for (unsigned int i = 0; i < m_States.size(); ++i)
    {
        if (m_States[i]->stateID == s)
        {
            m_ActiveStatePosition = i;
            return;
        }
    }

    std::cout << "Could not change state\n";
}

void StateManager::deleteState(StateID s)
{
    for (unsigned int i = 0; i < m_States.size(); ++i)
    {
        if (m_States[i]->stateID == s)
        {
            m_States.erase(m_States.begin() + i);
        }
    }
}

State& StateManager::getActiveState()
{
    if (m_States.size() == 0)
    {
        assert(!"Cannot get active state, no states available");
    }

    if (m_States[m_ActiveStatePosition]->stateID != m_States[m_ActiveStatePosition]->targetState)
    {
        auto newTargetState = m_States[m_ActiveStatePosition]->targetState; //Store which state to switch to
        m_States[m_ActiveStatePosition]->targetState = m_States[m_ActiveStatePosition]->stateID; //reset the state ID of the original state to its own ID
        this->changeState(newTargetState); //switch states base on the state we need to switch to
    }

    return *m_States[m_ActiveStatePosition];
}

} //ZGE
