//STD
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Utility.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"
#include "StateManager.hpp"
#include "Constants.hpp"
#include "FPS.hpp"
#include "ResourceManagement/ResourceManager.hpp"
#include "Game.hpp"

/*
TODO

Bombs

*/

int main(int argc, char **argv)
{
    std::srand(std::time(nullptr));

    std::cout << "###Main###\n";

    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }

    {
        Game game;
        game.run();
    }

    std::cout << "Exiting\n";
	return 0;
}
