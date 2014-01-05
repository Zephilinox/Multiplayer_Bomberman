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
#include "MenuState.hpp"

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
	    MenuState menuState;

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
		/*fps.setPosition(672 - fps.getLocalBounds().width, 0);

        world.update(prevFrame);

        ResMan.Update();*/

        menuState.update(window, sf::Time::Zero);

		//Draw
		window.clear(sf::Color(40, 40, 40));

        /*window.draw(world.getLevelFloor(), &ResMan.texture("tile"));
        window.draw(world);*/

        menuState.draw(window, sf::Time::Zero);
		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
		fps.setString(zge::toString(1.f / prevFrame.asSeconds()));
	}

	return 0;
}
