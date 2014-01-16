#include "BombManager.hpp"

std::vector<Bomb> BombManager::m_Bombs;

BombManager::BombManager()
{
    //ctor
}

void BombManager::addBomb(sf::Vector2f pos, unsigned int pow)
{
    Bomb b(pos, pow);
    m_Bombs.push_back(b);
}

void BombManager::drawBombs(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i = 0; i < m_Bombs.size(); ++i)
    {
        m_Bombs[i].draw(target, states);
    }
}
