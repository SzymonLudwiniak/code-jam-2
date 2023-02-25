#include <SFML/Graphics.hpp>


class PhysicalObject
{
public:
    virtual void setRealPosition(const sf::Vector2f &vec);
    virtual void setVelocity(const sf::Vector2f &vec);
    virtual void setAcceleration(const sf::Vector2f &vec);
    virtual void setMass(float mass);

    virtual void moveObject(const sf::Vector2f &vec);

    sf::Vector2f getRealPosition();
    sf::Vector2f getVelocity();
    sf::Vector2f getAcceleration();
    float getMass();

    virtual sf::Vector2f push(const sf::Vector2f &force) = 0;
protected:
    sf::Vector2f realPosition;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float mass;
};