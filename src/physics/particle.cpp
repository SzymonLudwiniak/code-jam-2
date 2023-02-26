#include "../../include/physics/particle.hpp"
#include "../../include/utility/defines.hpp"

Particle::Particle(const sf::Vector2f &position, float radius, int pointCount)
{
    setPosition(position);
    setMass(1.0);
    body.setPosition(position);
    body.setRadius(radius);
    body.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
    body.setOrigin(radius, radius);
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
    PhysicalObject::moveObject({vec.x*(*globalDelay), vec.y*(*globalDelay)});
    body.move({vec.x*(*globalDelay), vec.y*(*globalDelay)});
}

float Particle::getCollisionRadius()
{
    return body.getRadius();
}

void Particle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(body, states);
}

void Particle::update()
{
    moveObject(getVelocity());
    setVelocity((getVelocity()+getAcceleration()*(*globalDelay))*float(FRIC));
}