#include "MenuState.hpp"

//STD
#include <iostream>

//3RD

//SELF
#include "Menu.hpp"

MenuState::MenuState()
{
    this->stateID = zge::StateID::MenuState;
    this->targetState = this->stateID;

    m_MainMenu.addButton("button", "New Game");
    m_MainMenu.addButton("button", "Options");

    m_ActiveMenu = &m_MainMenu;
}

void MenuState::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        window.close();
        break;
    default:
        break;
    }

    m_ActiveMenu->handleEvent(event, window);
}

void MenuState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    m_ActiveMenu->update(window, delta);

    if (m_ActiveMenu == &m_MainMenu)
    {
        if (m_ActiveMenu->mouseClicked("New Game"))
        {
            //this->targetState = zge::StateID::GameState;
        }
    }
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    m_ActiveMenu->draw(target, states);
}
