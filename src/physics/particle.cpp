#include "../../include/physics/particle.hpp"


Particle::Particle(const sf::Vector2f &position, float radius, int pointCount)
: sf::CircleShape(radius, pointCount)
{
    PhysicalObject::setRealPosition(position);
    sf::CircleShape::setPosition(position);
    setMass(1.0);
}

Particle::~Particle()
{

}

sf::Vector2f Particle::push(const sf::Vector2f &force)
{
    setVelocity(force/getMass());
    return getVelocity();
}

void Particle::setRealPosition(const sf::Vector2f &vec)
{
    PhysicalObject::setRealPosition(vec);
    sf::CircleShape::setPosition(vec);
}

void Particle::moveObject(const sf::Vector2f &vec)
{
    PhysicalObject::moveObject(velocity);
    sf::CircleShape::move(velocity);
}

void Particle::update()
{
    
}