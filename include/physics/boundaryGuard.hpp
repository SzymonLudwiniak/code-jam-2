#pragma once
#include "physicalObject.hpp"


class BoundaryGuard
{
public:
    BoundaryGuard();
    ~BoundaryGuard();

    void checkBounds(std::vector<PhysicalObject*> &objects);
};