#ifndef FPS_HPP
#define FPS_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManagement/Resource.hpp"

class FPS : public sf::Drawable
{
public:
    FPS();
    ~FPS();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(sf::RenderWindow& window);

    void setFPS(float fps);

    void setUpdateRate(unsigned int ur);
    unsigned int getUpdateRate(void);

private:
    unsigned int m_UpdateRate;

    sf::Text m_Text;
    Resource<sf::Font> m_Font;
};

#endif //FPS_HPP
