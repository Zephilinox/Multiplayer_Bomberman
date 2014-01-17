#include "Player.hpp"

#include <iostream>
#include <cmath>

Player::Player()
{
    m_Sprite.setTexture(m_ResMan.texture("Circle"));
    m_Sprite.setPosition(64, 64);
    m_Destination = m_Sprite.getPosition();
    m_Source = m_Sprite.getPosition();

    m_SourceTile.setPosition(32, 32);
    m_SourceTile.setSize(sf::Vector2f(32, 32));
    m_DestinationTile = m_SourceTile;
    m_SpriteTile = m_SourceTile;

    m_SourceTile.setFillColor(sf::Color(0, 0, 255, 85));
    m_DestinationTile.setFillColor(sf::Color(255, 0, 0, 85));
    m_SpriteTile.setFillColor(sf::Color(0, 255, 0, 85));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_SourceTile, states);
    target.draw(m_DestinationTile, states);
    target.draw(m_SpriteTile, states);
    target.draw(m_Sprite, states);
}

void Player::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == m_Up ||
            event.key.code == m_Left ||
            event.key.code == m_Down ||
            event.key.code == m_Right)
        {
            m_LastKeyPressed = event.key.code;
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (m_LastKeyPressed == event.key.code);
        {
            m_LastKeyPressed = sf::Keyboard::Key::Unknown;
        }
    }
}

void Player::update(sf::Time delta, std::vector<std::vector<int>> collisionGrid)
{
    if (sf::Keyboard::isKeyPressed(m_Bomb) && m_BombSpawnTimer.getElapsedTime().asSeconds() >= 0.5f)
    {
        m_BombSpawnTimer.restart();
        m_BombMan.addBomb(m_SourceTile.getPosition(), m_BombPower);
    }

    //Look in to Up+Right with a wall blocking Right. Needs to still move Up.

    if (m_Source == m_Destination) //Not moving
    {
        if (m_LastKeyPressed == sf::Keyboard::Key::Unknown) //Last key pressed was not a movement one
        {
            if (sf::Keyboard::isKeyPressed(m_Up))
            {
                m_Destination.y = m_Source.y + -32;
            }
            else if (sf::Keyboard::isKeyPressed(m_Left))
            {
                m_Destination.x = m_Source.x + -32;
            }
            else if (sf::Keyboard::isKeyPressed(m_Down))
            {
                m_Destination.y = m_Source.y + 32;
            }
            else if (sf::Keyboard::isKeyPressed(m_Right))
            {
                m_Destination.x = m_Source.x + 32;
            }
            else
            {
                m_Destination = m_Source;
            }
        }
        else
        {
            if (m_LastKeyPressed == m_Up && sf::Keyboard::isKeyPressed(m_Up)) //Using LastKeyPressed so that the newest movement key press changes direction, making movement more fluid
            {
                m_Destination.y = m_Source.y + -32;
            }
            else if (m_LastKeyPressed == m_Left && sf::Keyboard::isKeyPressed(m_Left))
            {
                m_Destination.x = m_Source.x + -32;
            }
            else if (m_LastKeyPressed == m_Down && sf::Keyboard::isKeyPressed(m_Down))
            {
                m_Destination.y = m_Source.y + 32;
            }
            else if (m_LastKeyPressed == m_Right && sf::Keyboard::isKeyPressed(m_Right))
            {
                m_Destination.x = m_Source.x + 32;
            }
            else
            {
                m_Destination = m_Source;
            }
        }
    }

    if (collisionGrid[m_Destination.y / 32][m_Destination.x / 32] == 0) //Valid destination
    {
        if (m_Destination.x > m_Sprite.getPosition().x - 3 && m_Destination.x < m_Sprite.getPosition().x + 3) //Because of floating point movement. if within range of error then fix position
        {
            if (m_Destination.y > m_Sprite.getPosition().y - 3 && m_Destination.y < m_Sprite.getPosition().y + 3)
            {
                m_Sprite.setPosition(m_Destination);
                m_Source = m_Destination;
            }
            else
            {
                m_Sprite.move(0, (m_Destination.y - m_Source.y) * m_Acceleration * delta.asSeconds());
            }
        }
        else
        {
            m_Sprite.move((m_Destination.x - m_Source.x) * m_Acceleration * delta.asSeconds(), 0);
        }
    }
    else
    {
        m_Destination = m_Source;
    }

    m_SourceTile.setPosition(m_Source);
    m_DestinationTile.setPosition(m_Destination);
    m_SpriteTile.setPosition(int((m_Sprite.getPosition().x + 16) / 32) * 32, int((m_Sprite.getPosition().y + 16) / 32) * 32);
}

void Player::useWASD()
{
    m_Up = sf::Keyboard::Key::W;
    m_Left = sf::Keyboard::Key::A;
    m_Down = sf::Keyboard::Key::S;
    m_Right = sf::Keyboard::Key::D;
    m_Bomb = sf::Keyboard::Key::Space;
}

void Player::useArrows()
{
    m_Up = sf::Keyboard::Key::Up;
    m_Left = sf::Keyboard::Key::Left;
    m_Down = sf::Keyboard::Key::Down;
    m_Right = sf::Keyboard::Key::Right;
    m_Bomb = sf::Keyboard::Key::RControl;
}

void Player::setColor(sf::Color c)
{
    m_Sprite.setColor(c);
}
