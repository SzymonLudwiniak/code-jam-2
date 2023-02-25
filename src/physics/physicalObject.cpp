#include "../../include/physics/physicalObject.hpp"


void PhysicalObject::setRealPosition(const sf::Vector2f &vec)
{
    realPosition = vec;
}

void PhysicalObject::setVelocity(const sf::Vector2f &vec)
{
    velocity = vec;
}

void PhysicalObject::setAcceleration(const sf::Vector2f &vec)
{
    acceleration = vec;
}

void PhysicalObject::setMass(float mass)
{
    this->mass = mass;
}

void PhysicalObject::moveObject(const sf::Vector2f &vec)
{
    realPosition += vec;
}

sf::Vector2f PhysicalObject::getRealPosition()
{
    return realPosition;
}

sf::Vector2f PhysicalObject::getVelocity()
{
    return velocity;
}

sf::Vector2f PhysicalObject::getAcceleration()
{
    return acceleration;
}

float PhysicalObject::getMass()
{
    return mass;
}
