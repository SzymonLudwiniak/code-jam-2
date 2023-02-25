#include "../../include/game/game.hpp"

Game::Game(sf::VideoMode mode, const std::string &title,  unsigned int style, 
            const sf::ContextSettings &settings) 
: sf::RenderWindow(mode, title, style, settings)
{

}

Game::~Game()
{
    
}

void Game::init()
{

}

void Game::update()
{

}

void Game::run()
{
    init();

    while(isOpen())
    {
        handleEvents();

        clear(sf::Color(0x00, 0xCC, 0xFF));
        display();
    }
}

void Game::handleEvents()
{
    sf::Event event;
        
    while(pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                this->close();
                break;
            default:
                break;
        }
    }
}