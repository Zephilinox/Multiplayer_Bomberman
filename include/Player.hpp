#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"

namespace zge
{

class Player : public sf::Drawable
{
public:
    Player();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(int collisionGrid[21][21]);
private:
    sf::Sprite m_Sprite;
    ResourceManager m_ResMan;
    sf::Clock m_MoveTimer;
};

} //Namespace zge


#endif // PLAYER_HPP
