#include "Button.hpp"

//STD
#include <iostream>

namespace zge
{

ResourceManager Button::m_ResMan;

Button::Button(std::string textureName):
m_MouseClicked(false)
{
    m_Sprite.setTexture(m_ResMan.texture(textureName));
    m_Text.setFont(m_ResMan.font("arial"));
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
    target.draw(m_Text, states);
}

void Button::update(sf::RenderWindow& window)
{
    if (sf::Mouse::getPosition(window).x > m_Sprite.getPosition().x &&
        sf::Mouse::getPosition(window).x < m_Sprite.getPosition().x + this->getSize().x)
    {
        if (sf::Mouse::getPosition(window).y > m_Sprite.getPosition().y &&
        sf::Mouse::getPosition(window).y < m_Sprite.getPosition().y + this->getSize().y)
        {
            m_Text.setColor(sf::Color(255, 180, 0));

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_MouseClicked = true;
            }
        }
        else
        {
            m_Text.setColor(sf::Color::White);
        }
    }
    else
    {
        m_Text.setColor(sf::Color::White);
    }

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_MouseClicked = false;
    }
}

void Button::setCharacterSize(unsigned int x)
{
    m_Text.setCharacterSize(x);
    this->setString(m_Text.getString()); //Recenter text
}

void Button::setString(std::string str)
{
    m_Text.setString(str);
    m_Text.setPosition(m_Sprite.getPosition().x + 125 - m_Text.getLocalBounds().width/2,
                       m_Sprite.getPosition().y + 50 - m_Text.getLocalBounds().height);
}

std::string Button::getString()
{
    return m_Text.getString();
}

bool Button::mouseClicked()
{
    return m_MouseClicked;
}

sf::Vector2u Button::getSize()
{
    return m_Sprite.getTexture()->getSize();
}

void Button::setPosition(sf::Vector2f pos)
{
    m_Sprite.setPosition(pos);
}

} //ZGE

