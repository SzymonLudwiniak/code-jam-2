#include <SFML/Graphics.hpp>

#include "physicalObject.hpp"


class Particle : public sf::CircleShape, public PhysicalObject
{
public:
    Particle(const sf::Vector2f &position, float radius = 0.f, int pointCount = 30);
    ~Particle();

    virtual sf::Vector2f push(const sf::Vector2f &force);
    virtual void setRealPosition(const sf::Vector2f &vec);
    virtual void moveObject(const sf::Vector2f &vec);

    void update();
};