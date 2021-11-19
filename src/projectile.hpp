#pragma once

#ifndef _Projectile_CLASS_
#define _Projectile_CLASS_

#include "entity.hpp"

class Projectile : public Entity {
public:
    enum Type { PlayerProjectile,
        EnemyProjectile };

public:
    Projectile(Type type, sf::Vector2f direction, float x, float y);
    Projectile(float x, float y);

    Projectile::Type GetType();

    void Update(float dt);

private:
    Type type_;
    sf::Vector2f direction_;
    void initVariables();
};

#endif