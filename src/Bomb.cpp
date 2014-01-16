#include "Bomb.hpp"

Bomb::Bomb(sf::Vector2f pos, unsigned int pow):
m_MaxPower(pow)
{
    m_Sprite.setTexture(m_ResMan.texture("Circle"));
    m_Sprite.setColor(sf::Color::Black);
    m_Sprite.setPosition(pos);
}

void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
}

unsigned int Bomb::getPower()
{
    return m_MaxPower;
}
