#pragma once

#ifndef _Projectile_CLASS_
#define _Projectile_CLASS_

#include "entity.hpp"

class Projectile : public Entity {
public:
    enum Type { PlayerProjectile,
        EnemyProjectile };

public:
    Projectile(float x, float y);

    int GetDamage();
    Projectile::Type GetType();
    sf::Vector2f GetDirection();

    void SetType(Projectile::Type type);
    void SetDirection(sf::Vector2f direction);
    void SetDamage(int damage);

    void Update(float dt);

private:
    Type type_;
    sf::Vector2f direction_;

    int damage_;

    void initVariables();
};

#endif