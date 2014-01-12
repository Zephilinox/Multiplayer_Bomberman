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

std::vector<std::shared_ptr<State>> StateManager::m_States;
unsigned int StateManager::m_ActiveStatePosition;

StateManager::StateManager()
{
    m_ActiveStatePosition = 0;
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
        this->changeState(m_States[m_ActiveStatePosition]->targetState);
    }

    return *m_States[m_ActiveStatePosition];
}

} //ZGE
