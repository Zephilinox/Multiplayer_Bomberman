#include "Menu.hpp"

//STD
#include <iostream>

//SELF
#include "Constants.hpp"

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
    for (auto& b : m_Buttons)
    {
        b->update(window);
    }
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto b : m_Buttons)
    {
        b->draw(target, states);
    }
}

void Menu::addButton(std::string textureName, std::string buttonName)
{
    std::shared_ptr<Button> b(new Button(textureName));

    b->setString(buttonName);
    b->setCharacterSize(28);

    m_Buttons.push_back(std::move(b));

    calculateButtonPositions();
}

bool Menu::mouseClicked(std::string buttonName)
{
    for (unsigned int i = 0; i < m_Buttons.size(); ++i)
    {
        if (m_Buttons[i]->getString() == buttonName && m_Buttons[i]->mouseClicked())
        {
            std::cout << "Button " << m_Buttons[i]->getString() << " was clicked\n";
            return true;
        }
    }

    return false;
}

void Menu::calculateButtonPositions()
{
    if (m_Buttons.size() == 0) return;

    if (m_Buttons.size() % 2 == 0) //if the number of buttons is even
    {
        unsigned int LowerYButton = (m_Buttons.size()/2.f) - 1; //if size = 8, lower index = 4-1 = 3, upper would be 4, index is 0-based where as size is not
        m_Buttons[LowerYButton]->setPosition(sf::Vector2f(Constant::windowWidth/2 - m_Buttons[LowerYButton]->getSize().x/2,
                                                         Constant::windowHeight/2 - m_Buttons[LowerYButton]->getSize().y)); //top-left is 0, 0; so subtract all of y to place it above center screen

        unsigned int UpperYButton = (m_Buttons.size()/2.f);
        m_Buttons[UpperYButton]->setPosition(sf::Vector2f(Constant::windowWidth/2 - m_Buttons[UpperYButton]->getSize().x/2,
                                                         Constant::windowHeight/2)); //don't subtract size-y because the top is already in the center

        for (unsigned int i = 0; i < m_Buttons.size(); ++i)
        {
            if (i < LowerYButton)
            {
                //set the y-position of all buttons with an index lower than the LowerYButton as being said buttons y-pos minus the height of the button times by the distance in index's
                m_Buttons[i]->setPosition(sf::Vector2f(m_Buttons[LowerYButton]->getPosition().x,
                                                      m_Buttons[LowerYButton]->getPosition().y - (m_Buttons[i]->getSize().y * (LowerYButton - i))));
            }
            else if (i > UpperYButton)
            {
                //set the y-position of all buttons with an index higher than the UpperYButton as being said buttons y-pos plus the height of the button times by the distance in index's
                m_Buttons[i]->setPosition(sf::Vector2f(m_Buttons[UpperYButton]->getPosition().x,
                                                      m_Buttons[UpperYButton]->getPosition().y + (m_Buttons[i]->getSize().y * (i - UpperYButton))));
            }
        }
    }
    else //odd number of buttons
    {
        unsigned int CenterYButton = std::floor(m_Buttons.size()/2.f); //if size = 5, center index = 2.5 = 2, index is 0-based so index 2 = 3rd button, 2 below, 2 above, thus being center.
        m_Buttons[CenterYButton]->setPosition(sf::Vector2f(Constant::windowWidth/2 - m_Buttons[CenterYButton]->getSize().x/2,
                                                          Constant::windowHeight/2 - m_Buttons[CenterYButton]->getSize().y/2)); //top-left is 0, 0; so subtract half of y to place it in the center

        for (unsigned int i = 0; i < m_Buttons.size(); ++i)
        {
            if (i < CenterYButton)
            {
                //set the y-position of all buttons with an index lower than the CenterYButton as being said buttons y-pos minus the height of the button times by the distance in index's
                m_Buttons[i]->setPosition(sf::Vector2f(m_Buttons[CenterYButton]->getPosition().x,
                                                      m_Buttons[CenterYButton]->getPosition().y - (m_Buttons[i]->getSize().y * (CenterYButton - i))));
            }
            else if (i > CenterYButton)
            {
                //set the y-position of all buttons with an index higher than the CenterYButton as being said buttons y-pos plus the height of the button times by the distance in index's
                m_Buttons[i]->setPosition(sf::Vector2f(m_Buttons[CenterYButton]->getPosition().x,
                                                      m_Buttons[CenterYButton]->getPosition().y + (m_Buttons[i]->getSize().y * (i - CenterYButton))));
            }
        }
    }
}

} //ZGE

