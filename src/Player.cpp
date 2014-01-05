#include "Player.hpp"

#include <iostream>
#include <cmath>

Player::Player()
{
    m_Sprite.setTexture(m_ResMan.texture("Yellow"));
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

    m_Velocity = sf::Vector2f(0, 0);
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

}
