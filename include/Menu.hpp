#ifndef MENU_HPP
#define MENU_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Button.hpp"

namespace zge
{

class Menu : sf::Drawable
{
public:
    Menu();
    void handleEvent(sf::Event& event, sf::RenderWindow& window);
    void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void addButton(std::string textureName, std::string buttonName);
    bool mouseClicked(std::string buttonName);

    void calculateButtonPositions();

private:
    std::vector<Button> m_Buttons;
};

} //ZGE


#endif // MENU_HPP
