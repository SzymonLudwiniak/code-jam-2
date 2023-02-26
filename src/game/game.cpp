#include <time.h>
#include <iostream>
#include <cmath>

#include "../../include/game/game.hpp"
#include "../../include/utility/defines.hpp"


Game::Game(sf::VideoMode mode, const std::string &title,  unsigned int style, 
            const sf::ContextSettings &settings) 
: sf::RenderWindow(mode, title, style, settings), 
    explosion(), handler(), boundGuard(), objects(), counter(), score()
{
    //setFramerateLimit(60);
    playing = true;
    delay = new float;

    counter.setPosition({0.f, 0.f});
    score.setPosition({0.f, 50.f});

    Explosion::setGlobalDelay(delay);
    Explosion::setSoundBuffer("./resources/audio/fart.wav");
    PhysicalObject::setGlobalDelay(delay);

    explosion.setForce(50);


    objects = std::vector<PhysicalObject *>();

    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            objects.push_back(new Particle({rand()%(SCREENWIDTH-40)+20, rand()%(SCREENHEIGHT-40)+20}, rand()%20+5));
            objects.back()->setMass(rand()%10+1);
            objects.back()->setAcceleration({0.f, 0.f});
            objects.back()->push({rand()%100-200, rand()%100-200});
        }
    }

    font.loadFromFile("./resources/fonts/Ubuntu-B.ttf");

    popUp.setFont(font);
    popUp.setFillColor(sf::Color::Green);
    popUp.setOutlineColor(sf::Color::Black);

    popUp.setPosition(-2000.f, 0.f);
    popUp.setCharacterSize(90);
    popUp.setOutlineThickness(2);

    popUp.setString("PRZEGRALES!!! wynik: "+std::to_string(score.getScore()));

    buffer.loadFromFile("./resources/audio/fail.wav");
    sound.setBuffer(buffer);
}

Game::~Game()
{
    delete delay;
}

void Game::update()
{
    if(!playing)
    {
        return;
    }
    // physical state updates here //
    handler.handleCollisions(objects);
    boundGuard.checkBounds(objects);

    sf::Vector2f mPos = sf::Vector2f(sf::Mouse::getPosition(*this));
    for(auto &object : objects)
    {
        float dist = sqrtf((mPos.x - object->getPosition().x)*(mPos.x - object->getPosition().x) + 
                            (mPos.y - object->getPosition().y)*(mPos.y - object->getPosition().y));
        if(dist < object->getCollisionRadius())
        {
            popUp.setPosition({SCREENWIDTH/2-470.f, SCREENHEIGHT/2-100.f});

            sound.play(); 
            playing = false;
        }
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
                if(event.key.code == sf::Keyboard::Key::Space && playing)
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
                if(event.mouseButton.button == sf::Mouse::Left && playing)
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
    draw(popUp);
}