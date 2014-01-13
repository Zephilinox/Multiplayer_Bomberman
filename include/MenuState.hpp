#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

//STD

//3RD

//SELF
#include "State.hpp"
#include "Menu.hpp"

class MenuState : public zge::State
{
public:
    MenuState();
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    zge::Menu m_MainMenu;
    zge::Menu m_MultiplayerMenu;
    zge::Menu m_ActiveMenu; //Assign a menu to it.

    zge::ResourceManager m_ResMan;
};

#endif // MENUSTATE_HPP
