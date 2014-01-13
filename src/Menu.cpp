#include "Menu.hpp"

//STD
#include <iostream>

namespace zge
{

 Menu::Menu()
{
}

void Menu::handleEvent(sf::Event& event, sf::RenderWindow& window)
{

}

void Menu::update(sf::RenderWindow& window, const sf::Time& delta)
{
    for (Button& b : m_Buttons)
    {
        b.update(window);
    }
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (Button b : m_Buttons)
    {
        b.draw(target, states);
    }
}

void Menu::addButton(std::string textureName, std::string buttonName)
{
    Button b(textureName);
    b.setPosition(sf::Vector2f(704/2 - b.getSize().x/2, 704 - b.getSize().y - 500 + (m_Buttons.size() * 100)));
    b.setString(buttonName);
    b.setCharacterSize(28);

    m_Buttons.push_back(b);
}

bool Menu::mouseClicked(std::string buttonName)
{
    for (unsigned int i = 0; i < m_Buttons.size(); ++i)
    {
        if (m_Buttons[i].getString() == buttonName && m_Buttons[i].mouseClicked())
        {
            std::cout << "Button " << m_Buttons[i].getString() << " was clicked\n";
            return true;
        }
    }

    return false;
}

} //ZGE

