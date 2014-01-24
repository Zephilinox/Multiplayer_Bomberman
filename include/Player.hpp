#ifndef PLAYER_HPP
#define PLAYER_HPP

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"
#include "Bomb.hpp"
#include "BombManager.hpp"

class Player : public sf::Drawable
{
public:
    Player();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void handleEvent(sf::Event& event);
    void update(sf::Time dleta, std::vector<std::vector<int>> collisionGrid);
    void useWASD();
    void useArrows();

    void setColor(sf::Color c);
private:
    sf::Sprite m_Sprite;
    zge::ResourceManager m_ResMan;
    BombManager m_BombMan;
    unsigned int m_Acceleration = 3; //Increment by 1.5 up to 6 times (min 3, max 9)
    unsigned int m_BombPower = 7; //Increment by 1 up to 7?
    int m_Health = 10000;
    sf::Vector2f m_Source;
    sf::Vector2f m_Destination;
    sf::Vector2f m_TilePosition;
    sf::RectangleShape m_SourceTile;
    sf::RectangleShape m_DestinationTile;
    sf::RectangleShape m_SpriteTile;

    sf::Clock m_MoveTimer;
    sf::Clock m_BombSpawnTimer;

    sf::Keyboard::Key m_LastKeyPressed = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Up = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Left = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Down = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Right = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key m_Bomb = sf::Keyboard::Key::Unknown;
};

#endif // PLAYER_HPP
