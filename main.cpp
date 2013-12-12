#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char **argv)
{
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() < 10)
	{
		std::cout << clock.getElapsedTime().asSeconds() << "\n";
	}
	
	return 0;
}
