#include "Player.hpp"

#include <iostream>

namespace zge
{

Player::Player()
{
    m_Sprite.setTexture(m_ResMan.texture("Yellow"));
    m_Sprite.setPosition(32, 32);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
}

void Player::update(int collisionGrid[21][21])
{
    if (m_MoveTimer.getElapsedTime().asSeconds() > 0.1)
    {
        m_MoveTimer.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_Sprite.move(0, -32);
            if (collisionGrid[int (m_Sprite.getPosition().y / 32)][int (m_Sprite.getPosition().x / 32)] == 1)
            {
                m_Sprite.move(0, 32);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_Sprite.move(-32, 0);
            if (collisionGrid[int (m_Sprite.getPosition().y / 32)][int (m_Sprite.getPosition().x / 32)] == 1)
            {
                m_Sprite.move(32, 0);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_Sprite.move(0, 32);
            if (collisionGrid[int (m_Sprite.getPosition().y / 32)][int (m_Sprite.getPosition().x / 32)] == 1)
            {
                m_Sprite.move(0, -32);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_Sprite.move(32, 0);
            if (collisionGrid[int (m_Sprite.getPosition().y / 32)][int (m_Sprite.getPosition().x / 32)] == 1)
            {
                m_Sprite.move(-32, 0);
            }
        }
    }
}

} //Namespace zge
