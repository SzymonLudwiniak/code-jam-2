#include "physicalObject.hpp"


class CollisionHandler
{
public:
    CollisionHandler();

    ~CollisionHandler();

    int handleCollisions(std::vector<PhysicalObject*> &objects);

private:
    std::vector<std::pair<PhysicalObject*, PhysicalObject*>> naiveCollisionDetection(std::vector<PhysicalObject*> &objects);
    void performCollision(std::pair<PhysicalObject*, PhysicalObject*> &colliding);
};