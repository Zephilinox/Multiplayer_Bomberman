#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
//#include "Player.hpp"
#include "State.hpp"
#include "Map.hpp"
//#include "BombManager.hpp"

class GameState : public zge::State
{
public:
    GameState();
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    //Player m_Player1;
    //Player m_Player2;

    Map m_Map;
    //BombManager m_BombMan;
};

#endif //GAMESTATE_HPP
