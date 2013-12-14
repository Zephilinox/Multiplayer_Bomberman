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
		if (window.getSize().x != window.getSize().y)
		{
			//window.setSize(sf::Vector2u((window.getSize().x + window.getSize().y) / 2, (window.getSize().x + window.getSize().y) / 2));
			window.setSize(sf::Vector2u(window.getSize().y , window.getSize().y));
		}

		sf::Event event;
		window.pollEvent(event);
		switch(event.type)
		{
			case sf::Event::Closed:
			{
				window.close();
				break;
			}
			case sf::Event::MouseButtonPressed:
            {
                //ResMan.sound("fireworks");
                break;
            }
            case sf::Event::MouseWheelMoved:
            {
                if (ResMan.music("background3").getVolume() + event.mouseWheel.delta >= 0 && ResMan.music("background3").getVolume() + event.mouseWheel.delta <= 100)
                {
                    ResMan.music("background3").setVolume(ResMan.music("background3").getVolume() + event.mouseWheel.delta);
                }
            }
			default:
			{

			}
		}

		//Update
		fps.setPosition(672 - fps.getLocalBounds().width, 0);

        world.update(prevFrame);

        ResMan.Update();
		//Draw

		window.clear(sf::Color(40, 40, 40));

        window.draw(world.getLevelFloor(), &ResMan.texture("tile"));
        window.draw(world);

		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
		fps.setString(zge::toString(1.f / prevFrame.asSeconds()));
	}

	return 0;
}
