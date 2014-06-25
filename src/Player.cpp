#include "Player.hpp"

//STD
#include <iostream>
#include <cmath>

//3RD

//SELF
#include "Constants.hpp"

Player::Player(sf::Vector2f pos, sf::Color c):
m_Texture("textures/player.png")
{
    m_Sprite.setTexture(m_Texture.get());
    m_Sprite.setColor(c);
    m_Sprite.setPosition(pos);
    m_Destination = m_Sprite.getPosition();
    m_Source = m_Sprite.getPosition();

    m_SourceTile.setPosition(Constant::tileSize, Constant::tileSize);
    m_SourceTile.setSize(sf::Vector2f(Constant::tileSize, Constant::tileSize));
    m_DestinationTile = m_SourceTile;
    m_SpriteTile = m_SourceTile;

    m_SourceTile.setFillColor(sf::Color(0, 0, 255, 85));
    m_DestinationTile.setFillColor(sf::Color(255, 0, 0, 85));
    m_SpriteTile.setFillColor(sf::Color(0, 255, 0, 85));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_SourceTile, states);
    target.draw(m_DestinationTile, states);
    target.draw(m_SpriteTile, states);
    target.draw(m_Sprite, states);
}

void Player::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == m_Up ||
            event.key.code == m_Down)
        {
            m_LastVerticalKeyPressed = event.key.code;
            m_LastKeyPressed = event.key.code;
        }
        else if (event.key.code == m_Left ||
                 event.key.code == m_Right)
        {
            m_LastHorizontalKeyPressed = event.key.code;
            m_LastKeyPressed = event.key.code;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == m_Up &&
            m_LastVerticalKeyPressed == m_Up &&
            sf::Keyboard::isKeyPressed(m_Down))
        {
            m_LastVerticalKeyPressed = m_Down;
            m_LastKeyPressed = m_Down;
            return;
        }
        else if (event.key.code == m_Down &&
                 m_LastVerticalKeyPressed == m_Down &&
                 sf::Keyboard::isKeyPressed(m_Up))
        {
            m_LastVerticalKeyPressed = m_Up;
            m_LastKeyPressed = m_Up;
            return;
        }
        else if (event.key.code == m_Up ||
                 event.key.code == m_Down)
        {
            m_LastVerticalKeyPressed = sf::Keyboard::Key::Unknown;
            m_LastKeyPressed = m_LastHorizontalKeyPressed;
        }

        if (event.key.code == m_Left &&
            m_LastHorizontalKeyPressed == m_Left &&
            sf::Keyboard::isKeyPressed(m_Right))
        {
            m_LastHorizontalKeyPressed = m_Right;
            m_LastKeyPressed = m_Right;
            return;
        }
        else if (event.key.code == m_Right &&
                 m_LastHorizontalKeyPressed == m_Right &&
                 sf::Keyboard::isKeyPressed(m_Left))
        {
            m_LastHorizontalKeyPressed = m_Left;
            m_LastKeyPressed = m_Left;
            return;
        }
        else if (event.key.code == m_Left ||
                 event.key.code == m_Right)
        {
            m_LastHorizontalKeyPressed = sf::Keyboard::Key::Unknown;
            m_LastKeyPressed = m_LastVerticalKeyPressed;
        }

        if (m_LastHorizontalKeyPressed == sf::Keyboard::Key::Unknown &&
            m_LastVerticalKeyPressed == sf::Keyboard::Key::Unknown)
        {
            m_LastKeyPressed = sf::Keyboard::Key::Unknown;
        }
    }
}

void Player::verticalMovement()
{
    if (m_Source == m_Destination &&
        m_LastVerticalKeyPressed != sf::Keyboard::Key::Unknown)
    {
        if (m_LastVerticalKeyPressed == m_Up)
        {
            m_Destination.y = m_Source.y - Constant::tileSize;
        }
        else if (m_LastVerticalKeyPressed == m_Down)
        {
            m_Destination.y = m_Source.y + Constant::tileSize;
        }
    }
}

void Player::horizontalMovement()
{
    if (m_Source == m_Destination &&
        m_LastHorizontalKeyPressed != sf::Keyboard::Key::Unknown)
    {
        if (m_LastHorizontalKeyPressed == m_Left)
        {
            m_Destination.x = m_Source.x - Constant::tileSize;
        }
        else if (m_LastHorizontalKeyPressed == m_Right)
        {
            m_Destination.x = m_Source.x + Constant::tileSize;
        }
    }
}

void Player::update(sf::Time delta, Map& map)
{
    map.setCollisionGridSquare(sf::Vector2i(int((m_Sprite.getPosition().x + (Constant::tileSize/2)) / Constant::tileSize),
                                            int((m_Sprite.getPosition().y + (Constant::tileSize/2)) / Constant::tileSize)),
                                            GridValue::Empty);

    /*if (sf::Keyboard::isKeyPressed(m_Bomb) && m_BombSpawnTimer.getElapsedTime().asSeconds() >= delta.asSeconds())
    {
        m_BombSpawnTimer.restart();
        m_BombMan.addBomb(m_Source, m_BombPower);
    }*/

    //Look in to Up+Right with a wall blocking Right. Needs to still move Up.

    if (m_LastKeyPressed == m_LastHorizontalKeyPressed)
    {
        this->horizontalMovement();
        this->verticalMovement();
    }
    else if (m_LastKeyPressed == m_LastVerticalKeyPressed)
    {
        this->verticalMovement();
        this->horizontalMovement();
    }

    if (map.getCollisionGridSquare(sf::Vector2i(m_Destination.x / Constant::tileSize, m_Destination.y / Constant::tileSize)) == GridValue::Empty) //Valid destination
    {
        /*if (collisionGrid[m_Destination.y / Constant::tileSize][m_Destination.x / 32] == 3)
        {
            m_Health -= 1;
            std::cout << m_Health << "\n";
        }*/

        if (m_Destination.x > m_Sprite.getPosition().x - 3 && m_Destination.x < m_Sprite.getPosition().x + 3) //Because of floating point movement. if within range of error then fix position
        {
            if (m_Destination.y > m_Sprite.getPosition().y - 3 && m_Destination.y < m_Sprite.getPosition().y + 3)
            {
                m_Sprite.setPosition(m_Destination);
                m_Source = m_Destination;
            }
            else
            {
                m_Sprite.move(0, (m_Destination.y - m_Source.y) * m_Acceleration * delta.asSeconds());
            }
        }
        else
        {
            m_Sprite.move((m_Destination.x - m_Source.x) * m_Acceleration * delta.asSeconds(), 0);
        }
    }
    else
    {
        m_Destination = m_Source;
    }

    m_SourceTile.setPosition(m_Source);
    m_DestinationTile.setPosition(m_Destination);
    m_SpriteTile.setPosition(int((m_Sprite.getPosition().x + (Constant::tileSize/2)) / Constant::tileSize) * Constant::tileSize,
                             int((m_Sprite.getPosition().y + (Constant::tileSize/2)) / Constant::tileSize) * Constant::tileSize);

    map.setCollisionGridSquare(sf::Vector2i(int((m_Sprite.getPosition().x + (Constant::tileSize/2)) / Constant::tileSize),
                                            int((m_Sprite.getPosition().y + (Constant::tileSize/2)) / Constant::tileSize)),
                                            GridValue::Player);
}

void Player::useWASD()
{
    m_Up = sf::Keyboard::Key::W;
    m_Left = sf::Keyboard::Key::A;
    m_Down = sf::Keyboard::Key::S;
    m_Right = sf::Keyboard::Key::D;
    m_Bomb = sf::Keyboard::Key::Space;
}

void Player::useArrows()
{
    m_Up = sf::Keyboard::Key::Up;
    m_Left = sf::Keyboard::Key::Left;
    m_Down = sf::Keyboard::Key::Down;
    m_Right = sf::Keyboard::Key::Right;
    m_Bomb = sf::Keyboard::Key::RControl;
}
