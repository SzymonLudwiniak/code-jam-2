#include "../../include/utility/fpsCounter.hpp"


FpsCounter::FpsCounter()
{
    font.loadFromFile("./resources/fonts/Ubuntu-B.ttf");

    setFont(font);
    setFillColor(sf::Color::Green);
    setOutlineColor(sf::Color::Black);

    setPosition(0.f, 0.f);
    setCharacterSize(12);
    setOutlineThickness(2);

    drawTime = 1.f;

    previousTime = clock.getElapsedTime();
}

FpsCounter::~FpsCounter()
{

}

void FpsCounter::saveTime()
{
    currentTime = clock.getElapsedTime();
    drawTime = (currentTime.asSeconds() - previousTime.asSeconds());
    double fps = 1.f / drawTime;
    previousTime = currentTime;

    setString("delay[s]:"+std::to_string(drawTime)+"\nfps: "+std::to_string(fps));
}

double FpsCounter::getDrawTime()
{
    return drawTime;
}