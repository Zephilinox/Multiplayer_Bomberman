#ifndef GUI_HPP
#define GUI_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF

class GUI
{
public:
    GUI(unsigned int numPlayers);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setPlayerHealth(unsigned int player, unsigned int health);

private:
};

#endif //GUI_HPP
