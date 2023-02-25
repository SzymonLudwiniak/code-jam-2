#include <iostream>
#include "../include/game/game.hpp"


int main()
{
    Game game(sf::VideoMode(1600, 900), "code jam");

    game.run();

    return 0;
}