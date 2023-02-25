#include <SFML/Graphics.hpp>


class Particle : public sf::CircleShape
{
public:
    Particle();
    ~Particle();

    sf::Vector2f push(sf::Vector2f &force);

private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float mass;
};