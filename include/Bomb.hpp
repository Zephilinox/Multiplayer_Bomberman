#ifndef BOMB_HPP
#define BOMB_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"

class Bomb : sf::Drawable
{
public:
    Bomb(sf::Vector2f pos, unsigned int pow = 1);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    unsigned int getPower();
private:
    sf::Sprite m_Sprite;
    unsigned int m_MaxPower; //max length of explosion

    zge::ResourceManager m_ResMan;
};

#endif // BOMB_HPP
