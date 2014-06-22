#ifndef GAME_HPP
#define GAME_HPP

//STD

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "StateManager.hpp"
#include "FPS.hpp"

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    void handleEvent();
    void update();
    void draw();

    sf::RenderWindow m_Window;
    FPS m_Fps;

	sf::Clock m_Clock;
	sf::Time m_PrevFrame;
	sf::Event m_Event;
};

#endif //GAME_HPP
