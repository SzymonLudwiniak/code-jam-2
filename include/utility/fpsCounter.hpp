#pragma once
#include <SFML/Graphics.hpp>

class FpsCounter : public sf::Text
{
public:
    FpsCounter();
    ~FpsCounter();

    void saveTime();

    float getDrawTime();

private:
    sf::Font font;

    sf::Clock clock;

    sf::Time previousTime;
    sf::Time currentTime;

    float drawTime;
};