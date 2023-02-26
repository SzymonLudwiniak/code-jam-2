#pragma once
#include <SFML/Graphics.hpp>

#include "physicalObject.hpp"


class Particle : public sf::Drawable, public PhysicalObject
{
public:
    Particle(const sf::Vector2f &position, float radius = 0.f, int pointCount = 30);
    ~Particle();

    virtual sf::Vector2f push(const sf::Vector2f &force);
    virtual void setPosition(const sf::Vector2f &vec);
    virtual void moveObject(const sf::Vector2f &vec);

    virtual float getCollisionRadius();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void update();

private:
    sf::CircleShape body;
};