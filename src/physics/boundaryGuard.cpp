#include "../../include/physics/boundaryGuard.hpp"
#include "../../include/utility/defines.hpp"


BoundaryGuard::BoundaryGuard()
{

}

BoundaryGuard::~BoundaryGuard()
{

}

void BoundaryGuard::checkBounds(std::vector<PhysicalObject*> &objects)
{
    for(auto & obj : objects)
    {
        auto pos = obj->getPosition();
        auto vel = obj->getRelativeVelocity();
        sf::Vector2f newVel = obj->getVelocity();

        if(pos.x + vel.x < obj->getCollisionRadius() || pos.x + vel.x > SCREENWIDTH - obj->getCollisionRadius())
            newVel.x *= -1;
        if(pos.y + vel.y < obj->getCollisionRadius() || pos.y + vel.y > SCREENHEIGHT - obj->getCollisionRadius())
            newVel.y *= -1;
        
        obj->setVelocity(newVel);
    }
}