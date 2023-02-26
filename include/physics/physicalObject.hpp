#pragma once
#include <SFML/Graphics.hpp>


class PhysicalObject
{
public:
    static void setGlobalDelay(float *globalDelay);

    virtual void setPosition(const sf::Vector2f &vec);
    virtual void setVelocity(const sf::Vector2f &vec);
    virtual void setAcceleration(const sf::Vector2f &vec);
    virtual void setMass(float mass);
    virtual void setElasticity(float elasticity);

    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    sf::Vector2f getAcceleration();
    float getMass();
    float getElasticity();

    virtual float getCollisionRadius() = 0;

    virtual void moveObject(const sf::Vector2f &vec);
    virtual sf::Vector2f push(const sf::Vector2f &force) = 0;
protected:
    static inline float const *globalDelay = nullptr;

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float mass;
    float elasticity;
};