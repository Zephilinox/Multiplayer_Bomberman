#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

//STD
#include <vector>

//3RD

//SELF
#include "State.hpp"
//#include "GameState.hpp"
#include "MenuState.hpp"

namespace zge
{

class StateManager
{
public:
    StateManager();
    void addState(StateID s);
    void changeState(StateID s);
    void deleteState(StateID s);
    State& getActiveState();
private:
    static std::vector<std::shared_ptr<State>> m_States;
    static unsigned int m_ActiveStatePosition;
};

} //ZGE

#endif // STATEMANAGER_HPP
