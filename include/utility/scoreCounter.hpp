#pragma once
#include <SFML/Graphics.hpp>


class ScoreCounter : public sf::Text
{
public:
    ScoreCounter();
    ~ScoreCounter();

    void incrementScore();

    void setScore(int score);

    int getScore();

private:
    sf::Font font;

    int score;
};