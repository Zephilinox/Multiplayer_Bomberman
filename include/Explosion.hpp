#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"
#include "Utility.hpp"

class Explosion: public sf::Drawable
{
public:
    Explosion(sf::Vector2f bombPos, sf::Vector2f exploPos);
    void update();
    sf::Time getTimeAlive();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;

private:
    sf::Sprite m_Sprite;
    sf::Clock m_TimeAlive;
    zge::ResourceManager m_ResMan;
};

#endif // EXPLOSION_HPP
