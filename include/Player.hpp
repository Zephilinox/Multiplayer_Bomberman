#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"

class Player : public sf::Drawable
{
public:
    Player();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void handleEvent(sf::Event& event);
    void update(sf::Time dleta, std::vector<std::vector<int>> collisionGrid);
    void useWASD();
    void useArrows();
private:
    sf::Sprite m_Sprite;
    zge::ResourceManager m_ResMan;
    unsigned int m_Acceleration = 9; //Increment by 1.5 up to 6 times (max of 9)

    sf::Vector2f m_Source;
    sf::Vector2f m_Destination;
    sf::Vector2f m_TilePosition;
    sf::RectangleShape m_SourceTile;
    sf::RectangleShape m_DestinationTile;
    sf::RectangleShape m_SpriteTile;

    sf::Clock m_MoveTimer;

    sf::Keyboard::Key m_LastKeyPressed = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Up = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Left = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Down = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Right = sf::Keyboard::Key::Unknown;
};

#endif // PLAYER_HPP
