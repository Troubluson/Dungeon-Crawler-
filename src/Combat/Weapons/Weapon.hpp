#pragma once
#ifndef _WEAPON_CLASS_
#define _WEAPON_CLASS_

#include "Combat/PowerUps/PowerUp.hpp"
#include "Combat/Projectile.hpp"
#include "Utility/SpriteHelper.hpp"

using namespace std;
using namespace sf;
using namespace sprite;

class Weapon {
protected:
    int damage_;
    int range_;
    Vector2f projectileSize_;
    bool penetrates_ = false;
    const int maxPowerUps = 3;
    int getPowerUpCount();
    Sprite sprite_;
    Texture texture_;
    vector<PowerUp*> powerUps_;
    float cooldown_;
    float attackCooldownLength;
    float attackCooldownLeft;

public:
    Weapon(int damage, int range, Vector2f projectileSize, int rateOfFire, const std::string& spriteLocation);
    virtual ~Weapon() {};
    virtual list<Projectile*> Use(Vector2f dir, Vector2f origin) = 0;
    // virtual void Animate() = 0;
    void AddPowerUp(PowerUp* up);
    float GetAttackCooldown() { return cooldown_; };
};
#endif