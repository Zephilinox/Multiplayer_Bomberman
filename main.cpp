//STD
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Utility.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"
#include "StateManager.hpp"
#include "Constants.hpp"
#include "FPS.hpp"

zge::StateManager StateMan;
FPS fps;

int main(int argc, char **argv)
{
    std::cout << "###Main###\n";

    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }

    //Initialise
	sf::RenderWindow window(sf::VideoMode(Constants::windowWidth, Constants::windowHeight), "Bomberman");
	//window.setFramerateLimit(60);

    StateMan.addState(zge::StateID::MenuState);
    StateMan.addState(zge::StateID::GameState);

	sf::Clock clock;
	sf::Time prevFrame;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                default:
                {
                }
            }
            StateMan.getActiveState().handleEvent(event, window);
		}

		//Update
		fps.update(window);

        StateMan.getActiveState().update(window, prevFrame);

		//Draw
		window.clear(sf::Color(40, 40, 40));

        window.draw(StateMan.getActiveState());
		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
        fps.setFPS(std::floor(1.f / prevFrame.asSeconds()));
	}

    std::cout << "exiting\n";
	return 0;
}
