#ifndef GUI_HPP
#define GUI_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManagement/ResourceCache.hpp"

class GUI : public sf::Drawable
{
public:
    GUI();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    ResourceCache<sf::Texture> m_Textures;

    sf::Sprite m_Player1;
    sf::Sprite m_Player2;

};

#endif //GUI_HPP
