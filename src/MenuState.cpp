#include "MenuState.hpp"

//STD
#include <iostream>

//3RD

//SELF
#include "Button.hpp"

MenuState::MenuState():
m_newGame(zge::Button("button")),
m_newGame1(zge::Button("button")),
m_newGame2(zge::Button("button")),
m_newGame3(zge::Button("button")),
m_newGame4(zge::Button("button"))
{
    this->stateID = zge::StateID::MenuState;
    this->targetState = this->stateID;

    m_newGame.setPosition(sf::Vector2f(674/2 - m_newGame.getSize().x/2, 674 - m_newGame.getSize().y - 500));
    m_newGame.setString("Continue Game");
    m_newGame.setCharacterSize(28);

    m_newGame1.setPosition(sf::Vector2f(674/2 - m_newGame.getSize().x/2, 674 - m_newGame.getSize().y - 400));
    m_newGame1.setString("New Game");
    m_newGame1.setCharacterSize(28);

    m_newGame2.setPosition(sf::Vector2f(674/2 - m_newGame.getSize().x/2, 674 - m_newGame.getSize().y - 300));
    m_newGame2.setString("Load Game");
    m_newGame2.setCharacterSize(28);

    m_newGame3.setPosition(sf::Vector2f(674/2 - m_newGame.getSize().x/2, 674 - m_newGame.getSize().y - 200));
    m_newGame3.setString("Multiplayer Game");
    m_newGame3.setCharacterSize(28);

    m_newGame4.setPosition(sf::Vector2f(674/2 - m_newGame.getSize().x/2, 674 - m_newGame.getSize().y - 100));
    m_newGame4.setString("Options");
    m_newGame4.setCharacterSize(28);
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
}

void MenuState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    m_newGame.update(window);
    m_newGame1.update(window);
    m_newGame2.update(window);
    m_newGame3.update(window);
    m_newGame4.update(window);

    if (m_newGame1.mouseClicked())
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
    target.draw(m_newGame, states);
    target.draw(m_newGame1, states);
    target.draw(m_newGame2, states);
    target.draw(m_newGame3, states);
    target.draw(m_newGame4, states);
}
