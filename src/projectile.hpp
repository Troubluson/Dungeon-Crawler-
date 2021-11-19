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
    float GetTimeExisted();
    float GetTimeLifeSpan();
    float GetProjectileSpeed();

    void SetType(Projectile::Type type);
    void SetDirection(sf::Vector2f direction);
    void SetDamage(int damage);
    void SetProjectileSpeed(float projectileSpeed);
    void SetTimeLifeSpan(float timeLifeSpan);

    void Update(float dt);

private:
    Type type_;
    sf::Vector2f direction_;

    int damage_;
    float projectileSpeed_;
    float timeExisted_;
    float timeLifeSpan_;

    void initVariables();
    bool move(float dt, float x, float y);
};

#endif