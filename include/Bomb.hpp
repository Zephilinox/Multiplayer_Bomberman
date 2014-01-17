#ifndef BOMB_HPP
#define BOMB_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"
#include "Explosion.hpp"
#include "Map.hpp"

enum BombState {Idle = 0, Exploded, Dead};

class Bomb : public sf::Drawable
{
public:
    Bomb(sf::Vector2f pos, unsigned int pow = 1);
    void update(Map& levelMap);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    BombState getState();
    unsigned int getPower();
    sf::Vector2f getPosition();

private:
    sf::Sprite m_Sprite;
    unsigned int m_MaxPower; //max length of explosion
    BombState m_State;
    std::vector<Explosion> m_Explosions;
    sf::Clock m_TimeAlive;
    zge::ResourceManager m_ResMan;
};

#endif // BOMB_HPP
