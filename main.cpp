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
#include "World.hpp"
#include "Button.hpp"

zge::ResourceManager ResMan;

zge::World world;

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }

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
		window.pollEvent(event);
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

		//Update
		fps.setPosition(672 - fps.getLocalBounds().width, 0);

        /*world.update(prevFrame);

        ResMan.Update();*/
		//Draw

		window.clear(sf::Color(40, 40, 40));

        Button newGame("button");
        newGame.setPosition(sf::Vector2f(674/2 - newGame.getSize().x/2, 674 - newGame.getSize().y - 500));
        newGame.setString("Continue Game");
        newGame.setCharacterSize(28);

        Button newGame1("button");
        newGame1.setPosition(sf::Vector2f(674/2 - newGame.getSize().x/2, 674 - newGame.getSize().y - 400));
        newGame1.setString("New Game");
        newGame1.setCharacterSize(28);

        Button newGame2("button");
        newGame2.setPosition(sf::Vector2f(674/2 - newGame.getSize().x/2, 674 - newGame.getSize().y - 300));
        newGame2.setString("Load Game");
        newGame2.setCharacterSize(28);

        Button newGame3("button");
        newGame3.setPosition(sf::Vector2f(674/2 - newGame.getSize().x/2, 674 - newGame.getSize().y - 200));
        newGame3.setString("Multiplayer Game");
        newGame3.setCharacterSize(28);

        Button newGame4("button");
        newGame4.setPosition(sf::Vector2f(674/2 - newGame.getSize().x/2, 674 - newGame.getSize().y - 100));
        newGame4.setString("Options");
        newGame4.setCharacterSize(28);

        /*window.draw(world.getLevelFloor(), &ResMan.texture("tile"));
        window.draw(world);*/

        window.draw(newGame);
        window.draw(newGame1);
        window.draw(newGame2);
        window.draw(newGame3);
        window.draw(newGame4);
		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
		fps.setString(zge::toString(1.f / prevFrame.asSeconds()));
	}

	return 0;
}
