#pragma once
#include <SFML/Graphics.hpp>
#include <cstdint>
#include "../utility/fpsCounter.hpp"
#include "../explosion/Explosion.hpp"


class Game : 
public sf::RenderWindow 
{
public:
    Game(sf::VideoMode mode, const std::string &title,  unsigned int style = sf::Style::Default, 
        const sf::ContextSettings &settings = sf::ContextSettings());
    ~Game();

    
    void run();

private:
    FpsCounter counter;
    float *delay;

    std::vector<PhysicalObject *> objects;
    Explosion explosion;

    virtual void update();

    virtual void handleEvents();

    virtual void drawAll();
};