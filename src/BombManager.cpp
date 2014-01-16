#include "BombManager.hpp"

std::vector<Bomb> BombManager::m_Bombs;

BombManager::BombManager()
{
    //ctor
}

void BombManager::update()
{
    for (unsigned int i = 0; i < m_Bombs.size(); ++i)
    {
        if (m_Bombs[i].getState() != BombState::Dead)
        {
            m_Bombs[i].update();
        }
        else
        {
            //m_Bombs.erase(m_Bombs.begin() + i, m_Bombs.end() + i);
        }
    }
}

void BombManager::addBomb(sf::Vector2f pos, unsigned int pow)
{
    Bomb b(pos, pow);
    m_Bombs.push_back(b);
}

void BombManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i = 0; i < m_Bombs.size(); ++i)
    {
        target.draw(m_Bombs[i], states);
    }
}
