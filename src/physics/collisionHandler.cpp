#include <cmath>
#include <algorithm>

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

    return pairs.size();
}

std::vector<std::pair<PhysicalObject*, PhysicalObject*>> CollisionHandler::naiveCollisionDetection(std::vector<PhysicalObject*> &objects)
{
    auto pairs = std::vector<std::pair<PhysicalObject*, PhysicalObject*>>();

    // for(int i = 0; i < objects.size(); i++)
    // {
    //     for(int j = 0; j < objects.size(); j++)
    //     {
    //         // if(objects[i] == objects[j])
    //         //     continue;
            
    //         auto posi = objects[i]->getPosition() + objects[i]->getRelativeVelocity();
    //         auto posj = objects[j]->getPosition() + objects[j]->getRelativeVelocity();

    //         auto radi = objects[i]->getCollisionRadius();
    //         auto radj = objects[i]->getCollisionRadius();

    //         if((posi.x - posj.x)*(posi.x - posj.x) + (posi.y - posj.y)*(posi.y - posj.y) < (radi + radj)*(radi + radj))
    //         {
    //             //pairs.push_back({objects[i], objects[j]});
    //         }
    //     }
    // }
    std::sort(objects.begin(), objects.end(), [](PhysicalObject* a, PhysicalObject* b){
                                                    return a->getPosition().x > b->getPosition().x;
                                                });

    int start = 0;
    int end = 0;

    bool collision;

    for(int i = 1; i < objects.size(); i++)
    {
        collision = false;

        sf::Vector2f posi = objects[i]->getPosition() + objects[i]->getRelativeVelocity();
        float radi = objects[i]->getCollisionRadius();

        for(int j = start; j <= end; j++)
        {
            sf::Vector2f posj = objects[j]->getPosition() + objects[j]->getRelativeVelocity();
            float radj = objects[j]->getCollisionRadius();

            if(objects[j] != objects[i] && abs(posj.x - posi.x) < radj + radj)
            {
                float distPow = (posi.x - posj.x)*(posi.x - posj.x) + (posi.y - posj.y)*(posi.y - posj.y);
                if(distPow < (radi + radj)*(radi + radj))
                {
                    pairs.push_back({objects[i], objects[j]});
                }
                end = i;
                collision = true;
            }
        }

        if(collision == false)
        {
            start = i;
            end = i;
        }
    }
    return pairs;
}

void CollisionHandler::performCollision(std::pair<PhysicalObject*, PhysicalObject*> &colliding)
{
    sf::Vector2f v1;
    sf::Vector2f v2;

    sf::Vector2f u1 = colliding.first->getVelocity();
    sf::Vector2f u2 = colliding.second->getVelocity();

    sf::Vector2f pos1 = colliding.first->getPosition();
    sf::Vector2f pos2 = colliding.second->getPosition();

    float m1 = colliding.first->getMass();
    float m2 = colliding.second->getMass();

    float dist = sqrtf((pos1.x - pos2.x)*(pos1.x - pos2.x) + (pos1.y - pos2.y)*(pos1.y - pos2.y));

    auto normal = sf::Vector2f(pos2.x-pos1.x, pos2.y-pos1.y) / dist;
    auto tangent = sf::Vector2f(-normal.y, normal.x);

    float dpNorm1 = u1.x*normal.x + u1.y*normal.y;
    float dpNorm2 = u2.x*normal.x + u2.y*normal.y;
    
    float dpTan1 = u1.x*tangent.x + u1.y*tangent.y;
    float dpTan2 = u2.x*tangent.x + u2.y*tangent.y;

    //zasada zachowania pędu
    float p1 = (dpNorm1 * (m1 - m2) + 2.f * m2 * dpNorm2)/(m1+m2);
    float p2 = (dpNorm2 * (m2 - m1) + 2.f * m1 * dpNorm1)/(m1+m2);

    v1.x = tangent.x * dpTan1 + normal.x * p1;
    v1.y = tangent.y * dpTan1 + normal.y * p1;

    v2.x = tangent.x * dpTan2 + normal.x * p2;
    v2.y = tangent.y * dpTan2 + normal.y * p2;

    float elasticity = (colliding.first->getElasticity() + colliding.second->getElasticity())/2;

    colliding.first->setVelocity(v1*elasticity);
    colliding.second->setVelocity(v2*elasticity);
}