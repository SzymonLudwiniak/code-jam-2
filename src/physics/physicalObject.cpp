#include "../../include/physics/physicalObject.hpp"


void PhysicalObject::setGlobalDelay(float *globalDelay)
{
    PhysicalObject::globalDelay = globalDelay;
}

void PhysicalObject::setPosition(const sf::Vector2f &vec)
{
    position = vec;
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

void PhysicalObject::setElasticity(float elasticity)
{
    this->elasticity = elasticity;
}

sf::Vector2f PhysicalObject::getPosition()
{
    return position;
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

float PhysicalObject::getElasticity()
{
    return elasticity;
}

void PhysicalObject::moveObject(const sf::Vector2f &vec)
{
    position += vec;
}