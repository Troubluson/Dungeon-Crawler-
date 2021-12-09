#pragma once
#ifndef _COLLISIONSYSTEM_CLASS_
#define _COLLISIONSYSTEM_CLASS_
#include "Interfaces/ICollidable.hpp"

class CollisionSystem {
private:
    // hold all objects that participate in collision
    std::vector<ICollidable*> objectList;

public:
    CollisionSystem() {};
    void AddToCollisionList(ICollidable* obj);
    void RemoveFromCollisionList(ICollidable* obj);
    void ProcessCollisionList();
};

#endif
