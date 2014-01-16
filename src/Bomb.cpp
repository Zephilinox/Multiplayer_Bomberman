#include "Bomb.hpp"

Bomb::Bomb(sf::Vector2f pos, unsigned int pow):
m_MaxPower(pow),
m_State(BombState::Idle)
{
    m_Sprite.setTexture(m_ResMan.texture("Circle"));
    m_Sprite.setColor(sf::Color::Black);
    m_Sprite.setPosition(pos);
}

void Bomb::update()
{
    if (m_State == BombState::Idle && m_TimeAlive.getElapsedTime().asSeconds() > 3.f)
    {
        m_State = BombState::Exploded;
        m_TimeAlive.restart();
        //m_Sprite.setTexture(m_ResMan.getTexture("CentreExplosion"));
        m_Sprite.setColor(sf::Color(100, 100, 100));

        for (unsigned int j = 0; j < m_MaxPower; ++j)
        {
            Explosion e1(m_Sprite.getPosition(), sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y - (32 * j + 32))); //North
            Explosion e2(m_Sprite.getPosition(), sf::Vector2f(m_Sprite.getPosition().x + (32 * j + 32), m_Sprite.getPosition().y)); //East
            Explosion e3(m_Sprite.getPosition(), sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y + (32 * j + 32))); //South
            Explosion e4(m_Sprite.getPosition(), sf::Vector2f(m_Sprite.getPosition().x - (32 * j + 32), m_Sprite.getPosition().y)); //West
            m_Explosions.push_back(e1);
            m_Explosions.push_back(e2);
            m_Explosions.push_back(e3);
            m_Explosions.push_back(e4);
        }
    }

    if (m_State == BombState::Exploded)
    {
        for (unsigned int i = 0; i < m_Explosions.size(); ++i)
        {
            m_Explosions[i].update();
        }
    }

    if (m_State == BombState::Exploded && m_TimeAlive.getElapsedTime().asSeconds() >= 3.f)
    {
        m_Explosions.clear();
        m_Sprite.setColor(sf::Color(0, 0, 0, 0));
        m_State = BombState::Dead;
    }
}

void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);

    for (unsigned int i = 0; i < m_Explosions.size(); ++i)
    {
        m_Explosions[i].draw(target, states);
    }
}

BombState Bomb::getState()
{
    return m_State;
}

unsigned int Bomb::getPower()
{
    return m_MaxPower;
}
