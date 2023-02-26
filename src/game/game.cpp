#include <time.h>
#include <iostream>

#include "../../include/game/game.hpp"


Game::Game(sf::VideoMode mode, const std::string &title,  unsigned int style, 
            const sf::ContextSettings &settings) 
: sf::RenderWindow(mode, title, style, settings)
{
    //setFramerateLimit(60);
    srand(time(NULL));
    delay = new float;

    Explosion::setGlobalDelay(delay);
    Explosion::setSoundBuffer("./resources/audio/fart.wav");
    PhysicalObject::setGlobalDelay(delay);

    explosion.setForce(10);
}

Game::~Game()
{
    delete delay;
}

void Game::update()
{
    // physical state updates here //
    explosion.update();
    ///////////////////
    *delay = counter.getDrawTime();
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
                break;
            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mPos = sf::Mouse::getPosition(*this);
                    explosion.setPosition(sf::Vector2f(mPos));
                    explosion.igniteExplosion(objects);
                }
                break;
            default:
                break;
        }
    }
}

void Game::drawAll()
{
    // draw here //
    draw(explosion);
    //////////////
    draw(counter);
}