#include "Player.hpp"

#include <iostream>
#include <cmath>

namespace zge
{

Player::Player()
{
    m_Sprite.setTexture(m_ResMan.texture("Yellow"));
    m_Sprite.setPosition(32, 32);
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

void Player::update(sf::Time delta, int collisionGrid[21][21])
{

    //Destination = Source +/- direction
        //If destination is south of source, and detecting up movement, then destination should be source, not source + north
        //Can't do simple +=/-= source because then the destination will be too far from source

    //If x-destination is invalid, using y-source then negate x-destination
    //Vice versa for y

    //If sprites position is very close to being on destination, then set source to destination

    //If destination is not the same as source then the sprite has to move
        //set source to destination, set sprite position to destination (to avoid floating point sprite pos)

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (m_Destination.y - m_Source.y > 32) //Player is moving down
        {
            m_Destination.y = m_Source.y;
        }
        else
        {
            m_Destination.y = m_Source.y - 32; //Move up
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (m_Destination.y - m_Source.y == -32) //Player is moving up
        {
            m_Destination.y = m_Source.y;
        }
        else
        {
            m_Destination.y = m_Source.y + 32; //Move down
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (m_Destination.x - m_Source.x == 32) //Player is moving right
        {
            m_Destination.x = m_Source.x;
        }
        else
        {
            m_Destination.x = m_Source.x - 32; //Move left
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (m_Destination.x - m_Source.x == -32) //Player is moving left
        {
            m_Destination.x = m_Source.x;
        }
        else
        {
            m_Destination.x = m_Source.x + 32; //Move right
        }
    }

    /*if (collisionGrid[int(m_Destination.x/32)][int(m_Source.y/32)] == 1)
    {
        m_Destination.x = m_Source.x;
    }

    if (collisionGrid[int(m_Source.x/32)][int(m_Destination.y/32)] == 1)
    {
        m_Destination.y = m_Source.y;
    }*/

    if (collisionGrid[int(m_Destination.x/32)][int(m_Destination.y/32)] == 1)
    {
        m_Destination = m_Source;
    }

    if (collisionGrid[int((m_Sprite.getPosition().x + 16) / 32)][int(m_Source.y/32)] == 1)
    {
        m_Destination.x = m_Source.x;
    }

    if (collisionGrid[int(m_Source.x/32)][int((m_Sprite.getPosition().y + 16) / 32)] == 1)
    {
        m_Destination.y = m_Source.y;
    }

    if (m_Destination.x >= m_Sprite.getPosition().x - 1 && m_Destination.x <= m_Sprite.getPosition().x + 1) //If sprite xpos is within x destination by small error
    {
        if (m_Destination.y >= m_Sprite.getPosition().y - 1 && m_Destination.y <= m_Sprite.getPosition().y + 1) //If sprite ypos is within y destination by small error
        {
            m_Sprite.setPosition(m_Destination);
            m_Source = m_Destination;
            std::cout << "x: " << m_Destination.x << "/" << m_Sprite.getPosition().x << " | ";
            std::cout << "y: " << m_Destination.y << "/" << m_Sprite.getPosition().y << "\n";
        }
    }

    if (m_Destination == m_Source)
    {
        //sprite has reached its destination, not moving
    }
    else
    {
        //sprite is not at its destination, we have to move it
        sf::Vector2f direction = m_Destination - m_Sprite.getPosition();
        direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);

        //Normalised to get direction, now multiply by "acceleration" and delta to add speed
        m_Sprite.move(direction * 64.f * delta.asSeconds());
        std::cout << m_Destination.x << ":" << m_Destination.y << "\n";
        std::cout << direction.x * 64.f * delta.asSeconds() << ":" << direction.y * 64.f * delta.asSeconds() << "\n";
    }

    m_SourceTile.setPosition(m_Source);
    m_DestinationTile.setPosition(m_Destination);
    m_SpriteTile.setPosition(int((m_Sprite.getPosition().x + 16) / 32) * 32, int((m_Sprite.getPosition().y + 16) / 32) * 32);
}

} //Namespace zge
