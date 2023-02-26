#include "../../include/physics/collisionHandler.hpp"


CollisionHandler::CollisionHandler()
{

}

CollisionHandler::~CollisionHandler()
{

}

int CollisionHandler::handleCollisions(std::vector<PhysicalObject*> &objects)
{
    auto pairs = naiveCollisionDetection(objects);

    for(auto &pair : pairs)
    {
        performCollision(pair);
    }
}

std::vector<std::pair<PhysicalObject*, PhysicalObject*>> CollisionHandler::naiveCollisionDetection(std::vector<PhysicalObject*> &objects)
{
    auto pairs = std::vector<std::pair<PhysicalObject*, PhysicalObject*>>();

    for(int i = 0; i < objects.size(); i++)
    {
        for(int j = i+1; j < objects.size(); j++)
        {
            // if(objects[i] == objects[j])
            //     continue;
            
            auto posi = objects[i]->getPosition() + objects[i]->getVelocity();
            auto posj = objects[j]->getPosition() + objects[j]->getVelocity();

            auto radi = objects[i]->getCollisionRadius();
            auto radj = objects[i]->getCollisionRadius();

            if((posi.x - posj.x)*(posi.x - posj.x) + (posi.y + posj.y)*(posi.y + posj.y) < (radi + radj)*(radi + radj))
            {
                pairs.push_back({objects[i], objects[j]});
            }
        }
    }
    return pairs;
}

void performCollision(std::pair<PhysicalObject*, PhysicalObject*> &colliding)
{
    sf::Vector2f v1;
    sf::Vector2f v2;

    sf::Vector2f u1 = colliding.first->getVelocity();
    sf::Vector2f u2 = colliding.second->getVelocity();

    float m1 = colliding.first->getMass();
    float m2 = colliding.second->getMass();

    v1.x = (u1.x*(m1-m2) + 2*m2*u2.x)/(m1+m2);
    v1.y = (u1.y*(m1-m2) + 2*m2*u2.y)/(m1+m2);

    v2.x = (u2.x*(m2-m1) + 2*m1*u1.x)/(m1+m2);
    v2.y = (u2.y*(m2-m1) + 2*m1*u1.y)/(m1+m2);

    colliding.first->setVelocity(v1);
    colliding.second->setVelocity(v2);
}