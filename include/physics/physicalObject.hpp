#include <SFML/Graphics.hpp>


class PhysicalObject
{
public:
    virtual void setPosition(const sf::Vector2f &vec);
    virtual void setVelocity(const sf::Vector2f &vec);
    virtual void setAcceleration(const sf::Vector2f &vec);
    virtual void setMass(float mass);

    virtual void moveObject(const sf::Vector2f &vec);

    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    sf::Vector2f getAcceleration();
    float getMass();

    virtual sf::Vector2f push(const sf::Vector2f &force) = 0;
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float mass;
};