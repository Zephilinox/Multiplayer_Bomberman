#include "Bomb.hpp"

Bomb::Bomb(sf::Vector2f pos, unsigned int pow):
m_MaxPower(pow),
m_State(BombState::Idle)
{
    m_Sprite.setTexture(m_ResMan.texture("Circle"));
    m_Sprite.setColor(sf::Color::Black);
    m_Sprite.setPosition(pos);
}

void Bomb::update(Map& levelMap)
{
    levelMap.setCollisionGridSquare(sf::Vector2i(m_Sprite.getPosition().x / 32, m_Sprite.getPosition().y / 32), 2);

    if (m_State == BombState::Idle && m_TimeAlive.getElapsedTime().asSeconds() > 3.f)
    {
        m_State = BombState::Exploded;
        m_TimeAlive.restart();
        //m_Sprite.setTexture(m_ResMan.getTexture("CentreExplosion"));
        m_Sprite.setColor(sf::Color(100, 100, 100));

        bool northBlocked = false;
        bool eastBlocked = false;
        bool southBlocked = false;
        bool westBlocked = false;

        for (unsigned int j = 0; j < m_MaxPower; ++j)
        {
            //TODO: this can be reworked to less code dupe
            if (northBlocked == false)
            {
                sf::Vector2f ePos = sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y - (32 * j + 32));
                if (ePos.y >= 0)
                    {
                    Explosion e1(m_Sprite.getPosition(), ePos); //North

                    if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 1)
                    {
                        levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 0);
                        northBlocked = true;
                    }
                    else
                    {
                        if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 0)
                        {
                            levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 3);
                        }

                        m_Explosions.push_back(e1);
                    }
                }
            }

            if (eastBlocked == false)
            {
                sf::Vector2f ePos = sf::Vector2f(m_Sprite.getPosition().x + (32 * j + 32), m_Sprite.getPosition().y);
                if (ePos.x <= 704 - 32)
                {
                    Explosion e1(m_Sprite.getPosition(), ePos); //East

                    if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 1)
                    {
                        levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 0);
                        eastBlocked = true;
                    }
                    else
                    {
                        if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 0)
                        {
                            levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 3);
                        }

                        m_Explosions.push_back(e1);
                    }
                }
            }

            if (southBlocked == false)
            {
                sf::Vector2f ePos = sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y + (32 * j + 32));
                if (ePos.y <= 704 - 32)
                {
                    Explosion e1(m_Sprite.getPosition(), ePos); //South

                    if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 1)
                    {
                        levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 0);
                        southBlocked = true;
                    }
                    else
                    {
                        if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 0)
                        {
                            levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 3);
                        }

                        m_Explosions.push_back(e1);
                    }
                }
            }

            if (westBlocked == false)
            {
                sf::Vector2f ePos = sf::Vector2f(m_Sprite.getPosition().x - (32 * j + 32), m_Sprite.getPosition().y);
                if (ePos.x >= 0)
                {
                    Explosion e1(m_Sprite.getPosition(), ePos); //West

                    if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 1)
                    {
                        levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 0);
                        westBlocked = true;
                    }
                    else
                    {
                        if (levelMap.getCollisionGrid()[ePos.y / 32][ePos.x / 32] == 0)
                        {
                            levelMap.setCollisionGridSquare(sf::Vector2i(ePos.x / 32, ePos.y / 32), 3);
                        }

                        m_Explosions.push_back(e1);
                    }
                }
            }
        }
    }

    if (m_State == BombState::Exploded)
    {
        levelMap.setCollisionGridSquare(sf::Vector2i(m_Sprite.getPosition().x / 32, m_Sprite.getPosition().y / 32), 3);
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

    if (m_State == BombState::Dead)
    {
        levelMap.setCollisionGridSquare(sf::Vector2i(m_Sprite.getPosition().x / 32, m_Sprite.getPosition().y / 32), 0);
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

sf::Vector2f Bomb::getPosition()
{
    return m_Sprite.getPosition();
}
