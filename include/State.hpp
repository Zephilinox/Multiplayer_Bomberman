#ifndef STATE_HPP
#define STATE_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF

namespace zge
{

enum StateID {BaseState = 0, MenuState, GameState};

class State : public sf::Drawable
{
public:
    State();
    virtual ~State();

    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void print();

    StateID stateID = StateID::BaseState;
    StateID targetState = StateID::BaseState;
};

} //ZGE

#endif // STATE_HPP
