#ifndef BUTTON_HPP
#define BUTTON_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"

namespace zge
{

class Button : public sf::Drawable
{
public:
    Button(std::string textureName);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(sf::RenderWindow& window);
    void setCharacterSize(unsigned int x);
    void setString(std::string str);
    std::string getString();

    bool mouseClicked();

    sf::Vector2u getSize();
    void setPosition(sf::Vector2f);
private:
    sf::Sprite m_Sprite;
    sf::Text m_Text;

    bool m_MouseClicked;

    static ResourceManager m_ResMan;
};

} //ZGE

#endif // BUTTON_HPP
