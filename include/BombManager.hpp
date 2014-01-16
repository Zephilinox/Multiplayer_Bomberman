#ifndef BOMBMANAGER_HPP
#define BOMBMANAGER_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Bomb.hpp"

class BombManager
{
public:
    BombManager();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void addBomb(sf::Vector2f pos, unsigned int pow);
private:
    static std::vector<Bomb> m_Bombs;
    zge::ResourceManager m_ResMan;
};

#endif // BOMBMANAGER_HPP
