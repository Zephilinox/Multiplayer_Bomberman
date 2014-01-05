#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

//STD

//3RD

//SELF
#include "State.hpp"
#include "Button.hpp"

class MenuState : public zge::State
{
public:
    MenuState();
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void draw(sf::RenderWindow& window, const sf::Time& delta);
    virtual void pause();
    virtual void resume();
private:
    zge::Button m_newGame;
    zge::Button m_newGame1;
    zge::Button m_newGame2;
    zge::Button m_newGame3;
    zge::Button m_newGame4;

    bool m_Paused = false;
};

#endif // MENUSTATE_HPP
