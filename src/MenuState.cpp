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

    m_MainMenu.addButton("button", "Continue");
    m_MainMenu.addButton("button", "New Game");
    m_MainMenu.addButton("button", "Load Game");
    m_MainMenu.addButton("button", "Multiplayer");
    m_MainMenu.addButton("button", "Options");

    m_MultiplayerMenu.addButton("button", "1 PC vs 1 PC");
    m_MultiplayerMenu.addButton("button", "2 PC vs 2 NPC");
    m_MultiplayerMenu.addButton("button", "LAN");
    m_MultiplayerMenu.addButton("button", "WAN");
    m_MultiplayerMenu.addButton("button", "Leave Multiplayer"); //Need some kind of tree structure for storing menus with parent menus, this won't work for deeper nesting.

    /*m_ContinueGame.setPosition(sf::Vector2f(704/2 - m_ContinueGame.getSize().x/2, 704 - m_ContinueGame.getSize().y - 500));

    m_NewGame.setPosition(sf::Vector2f(704/2 - m_ContinueGame.getSize().x/2, 704 - m_ContinueGame.getSize().y - 400));

    m_LoadGame.setPosition(sf::Vector2f(704/2 - m_ContinueGame.getSize().x/2, 704 - m_ContinueGame.getSize().y - 300));

    m_Multiplayer.setPosition(sf::Vector2f(704/2 - m_ContinueGame.getSize().x/2, 704 - m_ContinueGame.getSize().y - 200));

    m_Options.setPosition(sf::Vector2f(704/2 - m_ContinueGame.getSize().x/2, 704 - m_ContinueGame.getSize().y - 100));*/

    m_ActiveMenu = m_MainMenu;
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

    m_ActiveMenu.handleEvent(event, window);
}

void MenuState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    m_ActiveMenu.update(window, delta);

    if (m_ActiveMenu.mouseClicked("New Game"))
    {
        std::cout << "AI not implemented, choose Multiplayer->1V1\n";

        //this->targetState = zge::StateID::GameState;
    }
    else if (m_ActiveMenu.mouseClicked("Multiplayer"))
    {
        m_ActiveMenu = m_MultiplayerMenu;
    }
    else if (m_ActiveMenu.mouseClicked("Leave Multiplayer"))
    {
        m_ActiveMenu = m_MainMenu;
    }
    else if (m_ActiveMenu.mouseClicked("1 PC vs 1 PC"))
    {
        this->targetState = zge::StateID::GameState;
    }
    else
    {
        this->targetState = this->stateID;
    }
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    m_ActiveMenu.draw(target, states);
}
