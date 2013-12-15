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
    void update(sf::Time dleta, int collisionGrid[21][21]); //Make some kind of Level manager so that the player can check with them rather than have the direct array
    //Need to change how it moves, either by making it more free-form (thus allowing explosions to clip you) or using a cur/target pos with update() making the sprite move between them like blastorium.
private:
    sf::Sprite m_Sprite;
    ResourceManager m_ResMan;
    sf::Vector2f m_Source;
    sf::Vector2f m_Destination;
    sf::RectangleShape m_SourceTile;
    sf::RectangleShape m_DestinationTile;
    sf::RectangleShape m_SpriteTile;
};

} //Namespace zge


#endif // PLAYER_HPP
