#pragma once
#ifndef _BOWWEAPON_CLASS_
#define _BOWWEAPON_CLASS_

#include "Combat/Weapons/Weapon.hpp"

class BowWeapon : public Weapon {
private:
public:
    BowWeapon(int damage, int range, int rateOfFire, float projectileSpeed, Vector2f projectileSize, const std::string& spriteLocation);
    virtual ~BowWeapon() { }
    virtual Projectile* Use(Vector2f dir, Vector2f origin);
};
#endif