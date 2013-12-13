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

zge::ResourceManager ResMan;

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

	int collisionGrid [21][21] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	for (int h = 0; h < 21; ++h)
	{
		collisionGrid[h][0] = 1;
		collisionGrid[h][20] = 1;
		collisionGrid[0][h] = 1;
		collisionGrid[20][h] = 1;

		for (int w = 0; w < 21; ++w)
		{
			if (h % 2 == 0 && w % 2 == 0)
			{
				collisionGrid[h][w] = 1;
			}
		}
	}

	//Map
	sf::VertexArray map(sf::Quads, 21*21*4);
	for (int h = 0; h < 672/32; ++h)
	{
		for (int w = 0; w < 672/32; ++w)
		{
			sf::Vertex TL;
			//TL.color = sf::Color::Red;
			TL.color = sf::Color::White;
			TL.texCoords = sf::Vector2f(0, 0);
			TL.position = sf::Vector2f(w*32, h*32);
			map.append(TL);

			sf::Vertex TR;
			//TR.color = sf::Color::Green;
			TR.color = sf::Color::White;
			TR.texCoords = sf::Vector2f(32, 0);
			TR.position = sf::Vector2f(w*32 + 32, h*32);
			map.append(TR);

			sf::Vertex BR;
			//BR.color = sf::Color::Blue;
			BR.color = sf::Color::White;
			BR.texCoords = sf::Vector2f(32, 32);
			BR.position = sf::Vector2f(w*32 + 32, h*32 + 32);
			map.append(BR);

			sf::Vertex BL;
			//BL.color = sf::Color::Yellow;
			BL.color = sf::Color::White;
			BL.texCoords = sf::Vector2f(0, 32);
			BL.position = sf::Vector2f(w*32, h*32 + 32);
			map.append(BL);
		}
	}

    ResMan.music("background3").setLoop(true);
    ResMan.music("background3").play();

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
                ResMan.sound("fireworks");
                break;
            }
			default:
			{

			}
		}

		//Update
		fps.setPosition(672 - fps.getLocalBounds().width, 0);

        ResMan.Update();

		//Draw

		window.clear(sf::Color(40, 40, 40));

		window.draw(map, &(ResMan.texture("tile")));

		for (int h = 0; h < 21; ++h)
		{
			for (int w = 0; w < 21; ++w)
			{
				if (collisionGrid[h][w] == 1)
				{
					sf::Sprite s;
					s.setTexture(ResMan.texture("tile2"));
					s.setPosition(w*32, h*32);
					window.draw(s);
				}
			}
		}

		window.draw(fps);
		window.display();

		prevFrame = clock.restart();
		fps.setString(zge::toString(1.f / prevFrame.asSeconds()));
	}

	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; j++)
		{
			std::cout << collisionGrid[i][j] << ", ";
		}

		std::cout << "\n";
	}

	return 0;
}
