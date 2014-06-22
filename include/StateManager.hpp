#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

//STD
#include <vector>

//3RD

//SELF
#include "State.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

namespace zge
{

class StateManager
{
public:
    ~StateManager();

    static StateManager& getInstance();
    static void deleteInstance();

    void addState(StateID s);
    void changeState(StateID s);
    void deleteState(StateID s);
    State& getActiveState();

private:
    StateManager();

    std::vector<std::shared_ptr<State>> m_States;
    unsigned int m_ActiveStatePosition;

    static std::unique_ptr<StateManager> m_Instance;
};

} //ZGE

#endif // STATEMANAGER_HPP
