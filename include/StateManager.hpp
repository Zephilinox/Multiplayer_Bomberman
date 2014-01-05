#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

//STD
#include <vector>

//3RD

//SELF
#include "State.hpp"

namespace zge
{

class StateManager
{
public:
    StateManager();
private:
    std::vector<State> m_States;
};

} //ZGE

#endif // STATEMANAGER_HPP
