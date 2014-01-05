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
#include "Player.hpp"
#include "GameState.hpp"
#include "Button.hpp"
#include "MenuState.hpp"

zge::ResourceManager ResMan;

GameState gameState;
MenuState menuState;

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }

    //Initialise
	sf::RenderWindow window(sf::VideoMode(672, 672), "Bomberman");
	window.setFramerateLimit(60);

	sf::Text fps;
	fps.setFont(ResMan.font("arial"));
	fps.setColor(sf::Color::White);

    //ResMan.music("background3").setLoop(true);
    //ResMan.music("background3").play();

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

            menuState.handleEvent(event, window);
		}

		//Update
		fps.setPosition(672 - fps.getLocalBounds().width, 0);
        gameState.update(window, prevFrame);
        ResMan.Update();
        menuState.update(window, sf::Time::Zero);

		//Draw
		window.clear(sf::Color(40, 40, 40));

        window.draw(gameState.getLevelFloor(), &ResMan.texture("tile"));
        window.draw(gameState);

        window.draw(menuState);

		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
		fps.setString(zge::toString(1.f / prevFrame.asSeconds()));
	}

	return 0;
}
