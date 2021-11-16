#pragma once
#ifndef _Projectile_CLASS_
#define _Projectile_CLASS_

#include "entity.hpp"

class Projectile : public Entity {
public:
    Projectile(float x, float y);
    virtual ~Projectile();
    void Update(float dt);

private:
    void initVariables();
};

#endif