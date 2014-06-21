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
    m_StateMan = new zge::StateManager;

    //Some sort of memory leak regarding fonts and textures with these buttons
    m_MainMenu.addButton("button", "New Game");
    m_MainMenu.addButton("button", "Options");
    m_MainMenu.addButton("button", "Quit");

    m_PauseMenu.addButton("button", "Continue");
    m_PauseMenu.addButton("button", "Options");
    m_PauseMenu.addButton("button", "Exit to Main Menu");

    m_ActiveMenu = &m_MainMenu;
}

MenuState::~MenuState()
{
    std::cout << "[MenuState] Destructor\n";
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
            m_StateMan->deleteState(zge::StateID::GameState);
            m_StateMan->addState(zge::StateID::GameState);
            this->targetState = zge::StateID::GameState;
            m_ActiveMenu = &m_PauseMenu;
        }
        else if (m_ActiveMenu->mouseClicked("Options"))
        {
            //TODO
        }
        else if (m_ActiveMenu->mouseClicked("Quit"))
        {
            window.close();
        }
    }
    else if (m_ActiveMenu == &m_PauseMenu)
    {
        if (m_ActiveMenu->mouseClicked("Continue"))
        {
            this->targetState = zge::StateID::GameState;
        }
        else if (m_ActiveMenu->mouseClicked("Options"))
        {
            //TODO
        }
        else if (m_ActiveMenu->mouseClicked("Exit to Main Menu"))
        {
            m_ActiveMenu = &m_MainMenu;
            sf::sleep(sf::seconds(0.5));
        }
    }
}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    m_ActiveMenu->draw(target, states);
}
