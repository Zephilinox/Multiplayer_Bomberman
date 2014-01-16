#include "Explosion.hpp"

//STD
#include <assert.h>
#include <iostream>

Explosion::Explosion(sf::Vector2f bombPos, sf::Vector2f exploPos)
{
    m_Sprite.setTexture(m_ResMan.texture("Circle"));

    if (exploPos.y < bombPos.y)
    {
        //m_Sprite.setTexture(m_ResMan.texture("NorthExplosion"));
    }
    else if (exploPos.x > bombPos.x) // East
    {
        //m_Sprite.setTexture(m_ResMan.texture("EastExplosion"));
    }
    else if (exploPos.y > bombPos.y) //South
    {
        //m_Sprite.setTexture(m_ResMan.texture("SouthExplosion"));
    }
    else if (exploPos.x < bombPos.x) //West
    {
        //m_Sprite.setTexture(m_ResMan.texture("WestExplosion"));
    }
    else
    {
        std::cout << bombPos.x << ":" << bombPos.y << "\n";
        std::cout << exploPos.x << ":" << exploPos.y << "\n";
        assert(!"exploPos cannot equal bombPos in Explosion::Explosion");
    }

    m_Sprite.setPosition(exploPos);
}

void Explosion::update()
{
    double curTime = m_TimeAlive.getElapsedTime().asSeconds();
    if (curTime - 1 > 0 && curTime - 1 <= 1)
    {
        m_Sprite.setColor(sf::Color(255, 255, 255, 255 * 0.8));
    }
    else if (curTime - 2 > 0 && curTime - 2 <= 1)
    {
        m_Sprite.setColor(sf::Color(255, 255, 255, 255 * 0.6));
    }
    else if (curTime - 3 > 0 && curTime - 3 <= 1)
    {
        m_Sprite.setColor(sf::Color(255, 255, 255, 255 * 0.4));
    }
    else if (curTime - 4 > 0 && curTime - 4 <= 1)
    {
        m_Sprite.setColor(sf::Color(255, 255, 255, 255 * 0.2));
    }
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
}

sf::Time Explosion::getTimeAlive()
{
    return m_TimeAlive.getElapsedTime();
}
