#include <iostream>
#include "../include/game/game.hpp"
#include "../include/utility/defines.hpp"

int main()
{
    srand(time(NULL));
    Game game(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "code jam");

    game.run();

    return 0;
}