#include "GameState.hpp"

GameState::GameState()
{
    this->stateID = zge::StateID::GameState;
    this->targetState = stateID;

    m_Player1.useWASD();
    m_Player1.setColor(sf::Color(200, 0, 0));

    m_Player2.useArrows();
    m_Player2.setColor(sf::Color(0, 0, 200));
}

void GameState::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    m_Player1.handleEvent(event);
    m_Player2.handleEvent(event);
}

void GameState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    m_Map.update(delta);

    m_Player1.update(delta, m_Map.getCollisionGrid());
    m_Player2.update(delta, m_Map.getCollisionGrid());

    m_BombMan.update(m_Map);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->targetState = zge::StateID::MenuState;
    }
    else
    {
        this->targetState = this->stateID;
    }
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Map, states);
    m_BombMan.draw(target, states);
    target.draw(m_Player1, states);
    target.draw(m_Player2, states);
}
