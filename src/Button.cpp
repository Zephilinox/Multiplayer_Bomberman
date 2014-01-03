#include "Button.hpp"

zge::ResourceManager Button::m_ResMan;

Button::Button(std::string textureName)
{
    m_Sprite.setTexture(m_ResMan.texture(textureName));
    m_Text.setFont(m_ResMan.font("Arial"));
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
    target.draw(m_Text, states);
}

void Button::update()
{

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

bool Button::isMouseOn()
{
    return false;
}

bool Button::mouseClicked()
{
    return false;
}

sf::Vector2u Button::getSize()
{
    return m_Sprite.getTexture()->getSize();
}

void Button::setPosition(sf::Vector2f pos)
{
    m_Sprite.setPosition(pos);
}


