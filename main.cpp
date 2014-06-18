//STD
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"
#include "Utility.hpp"
//#include "GameState.hpp"
#include "MenuState.hpp"
#include "StateManager.hpp"
#include "Constants.hpp"

zge::ResourceManager ResMan;
zge::StateManager StateMan;

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

	sf::Text fps;
	fps.setFont(ResMan.font("arial"));
	fps.setColor(sf::Color::White);

    //ResMan.music("background3").setLoop(true);
    //ResMan.music("background3").play();

    StateMan.addState(zge::StateID::MenuState);
    //StateMan.addState(zge::StateID::GameState);

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
		fps.setPosition(Constants::windowWidth - fps.getLocalBounds().width, 0);
		ResMan.Update();

        StateMan.getActiveState().update(window, prevFrame);

		//Draw
		window.clear(sf::Color(40, 40, 40));

        window.draw(StateMan.getActiveState());

		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
        fps.setString(zge::toString(std::floor(1.f / prevFrame.asSeconds())));
	}

	return 0;
}
