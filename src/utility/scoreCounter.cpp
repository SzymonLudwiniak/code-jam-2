#include "../../include/utility/scoreCounter.hpp"


ScoreCounter::ScoreCounter()
{
    font.loadFromFile("./resources/fonts/Ubuntu-B.ttf");

    setFont(font);
    setFillColor(sf::Color::Green);
    setOutlineColor(sf::Color::Black);

    setPosition(0.f, 0.f);
    setCharacterSize(32);
    setOutlineThickness(2);

    score = 0;
    setString("score: "+std::to_string(score));
}

ScoreCounter::~ScoreCounter()
{

}

int ScoreCounter::getScore()
{
    return score;
}

void ScoreCounter::incrementScore()
{
    score++;
    setString("score: "+std::to_string(score));
}

void ScoreCounter::setScore(int score)
{
    this->score = score;
}