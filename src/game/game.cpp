#include <time.h>
#include <iostream>

#include "../../include/game/game.hpp"
#include "../../include/utility/defines.hpp"


Game::Game(sf::VideoMode mode, const std::string &title,  unsigned int style, 
            const sf::ContextSettings &settings) 
: sf::RenderWindow(mode, title, style, settings), 
    explosion(), handler(), boundGuard(), objects(), counter(), score()
{
    //setFramerateLimit(60);
    delay = new float;

    counter.setPosition({0.f, 0.f});
    score.setPosition({0.f, 50.f});

    Explosion::setGlobalDelay(delay);
    Explosion::setSoundBuffer("./resources/audio/fart.wav");
    PhysicalObject::setGlobalDelay(delay);

    explosion.setForce(50);


    objects = std::vector<PhysicalObject *>();

    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 30; x++)
        {
            objects.push_back(new Particle({x*50+100+y, y*30+200}, rand()%10+1));
            objects.back()->setMass(rand()%10+1);
            objects.back()->setAcceleration({0.f, G});
        }
    }
}

Game::~Game()
{
    delete delay;
}

void Game::update()
{
    // physical state updates here //
    handler.handleCollisions(objects);
    boundGuard.checkBounds(objects);

    for(auto &object : objects)
    {
        object->update();
    }
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
                    for(auto &obj : objects)
                    {
                        obj->setVelocity({0.f, 0.f});
                        obj->setPosition({rand()%1000+50, rand()%600+50});
                        obj->push({rand()%500, rand()%500});
                    }
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
                    if(explosion.igniteExplosion(objects))
                        score.incrementScore();
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
    for(auto &object : objects)
    {
        draw(*object);
    }
    draw(explosion);
    //////////////
    draw(score);
    draw(counter);
}