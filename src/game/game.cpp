#include <time.h>
#include <iostream>

#include "../../include/game/game.hpp"


Game::Game(sf::VideoMode mode, const std::string &title,  unsigned int style, 
            const sf::ContextSettings &settings) 
: sf::RenderWindow(mode, title, style, settings)
{
    srand(time(NULL));
}

Game::~Game()
{
    
}

void Game::update()
{
    // physical state updates here //

    ///////////////////
    counter.saveTime();
}

void Game::run()
{

    while(isOpen())
    {
        handleEvents();

        update();
        clear(sf::Color(0x00, 0xCC, 0xFF));
        drawAll();
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
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Key::Space)
                {

                }
                else if(event.key.code == sf::Keyboard::Key::Escape)
                {
                    this->close();
                }
            default:
                break;
        }
    }
}

void Game::drawAll()
{
    // draw here //

    //////////////
    draw(counter);
}