#ifndef STATE_HPP
#define STATE_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF

namespace zge
{

class State : public sf::Drawable
{
public:
    State() = default;
    virtual ~State() = default;

    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(sf::RenderWindow& window, const sf::Time& delta) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

} //ZGE

#endif // STATE_HPP
