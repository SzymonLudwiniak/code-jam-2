#include "../../include/physics/particle.hpp"


Particle::Particle(const sf::Vector2f &position, float radius, int pointCount)
{
    setPosition(position);
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

void Particle::setPosition(const sf::Vector2f &vec)
{
    PhysicalObject::setPosition(vec);
    body.setPosition(vec);
}

void Particle::moveObject(const sf::Vector2f &vec)
{
    PhysicalObject::moveObject(vec);
    body.CircleShape::move(vec);
}

void Particle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void Particle::update()
{
    moveObject(getVelocity());
}