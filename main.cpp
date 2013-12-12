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

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "Hello");
	window.setFramerateLimit(60);
	
	sf::Font arial;
	arial.loadFromFile("fonts/arial.ttf");
	
	sf::Text fps;
	fps.setFont(arial);
	fps.setColor(sf::Color::White);
	
	sf::Texture tile;
	tile.loadFromFile("textures/tile.png");
	
	sf::Texture tile2;
	tile2.loadFromFile("textures/tile2.png");
	
	int collisionGrid [20][20] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	
	std::vector<std::vector<sf::Sprite> > collisionSprites;
	collisionSprites.resize(20);
	for (int i = 0; i < 20; ++i)
	{
		collisionSprites[i].resize(20);
	}
	
	for (int i = 0; i < 20; ++i)
	{
		
		collisionGrid[0][0] = 1;
		collisionGrid[i][0] = 1;
		collisionGrid[i][19] = 1;
		collisionGrid[0][i] = 1;
		collisionGrid[19][i] = 1;
	}
	
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			//if (collisionGrid[i][j] == 1)
			{
				sf::Sprite s(tile2);
				s.setPosition(i*32, j*32);
				collisionSprites[i].push_back(s);
			}
		}
	}
	//Map
	sf::VertexArray map(sf::Quads, 1600);
	for (int h = 0; h < 640/32; ++h)
	{
		for (int w = 0; w < 640/32; ++w)
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
			}
			default:
			{
				
			}
		}
		
		//Update
		fps.setPosition(640 - fps.getLocalBounds().width, 0);
		
		//Draw
		//http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php
		
		window.clear(sf::Color(40, 40, 40));
	
		window.draw(map, &tile);
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				window.draw(collisionSprites[i][j]);
			}
		}
		sf::Sprite solid;
		solid.setTexture(tile2);
		solid.setPosition(sf::Vector2f(320, 320));
		window.draw(solid);
		window.draw(collisionSprites[0][0]);
		window.draw(fps);
		
		window.display();
		
		prevFrame = clock.restart();
		fps.setString(zge::toString(1.f / prevFrame.asSeconds()));	
	}
	
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << collisionGrid[i][j] << ", ";
		}
		
		std::cout << "\n";
	}
	
	return 0;
}
