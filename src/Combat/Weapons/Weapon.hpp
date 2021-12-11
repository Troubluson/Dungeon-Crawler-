#pragma once
#ifndef _WEAPON_CLASS_
#define _WEAPON_CLASS_

#include "Combat/PowerUps/PowerUp.hpp"
#include "Combat/Projectile.hpp"
#include "Utility/SpriteHelper.hpp"

using namespace std;
using namespace sf;

class Weapon {
public:
    Weapon(int damage, int range, int rateOfFire, float projectileSpeed, Vector2f projectileSize, const std::string& spriteLocation);
    virtual ~Weapon() {};
    virtual Projectile* Use(Vector2f dir, Vector2f origin) = 0;
    // virtual void Animate() = 0;
    void AddPowerUp(PowerUp* up);
    float GetAttackCooldown() { return cooldown_; };
    float GetRange() { return range_; };

protected:
    int damage_;
    int range_;
    float projectileSpeed_;
    Vector2f projectileSize_;
    int speed_;
    bool penetrates_ = false;
    const int maxPowerUps = 3;
    int getPowerUpCount();
    Sprite sprite_;
    Texture texture_;
    vector<PowerUp*> powerUps_;
    float cooldown_;
    float attackCooldownLength_;
    float attackCooldownLeft;
};
#endif
