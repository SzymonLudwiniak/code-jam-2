#pragma once
#include <SFML/Graphics.hpp>


class PhysicalObject : public sf::Drawable
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
    sf::Vector2f getRelativeVelocity();
    sf::Vector2f getAcceleration();
    
    float getMass();
    float getElasticity();

    virtual float getCollisionRadius() = 0;

    virtual void moveObject(const sf::Vector2f &vec);
    virtual sf::Vector2f push(const sf::Vector2f &force);
    virtual void update() = 0;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected:
    static inline float const *globalDelay = nullptr;

private:
    sf::Vector2f position = {0.f, 0.f};
    sf::Vector2f velocity = {0.f, 0.f};
    sf::Vector2f acceleration = {0.f, 0.f};

    float mass = 1.f;
    float elasticity = 1.f;
};