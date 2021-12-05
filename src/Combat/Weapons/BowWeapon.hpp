#pragma once
#ifndef _BOWWEAPON_CLASS_
#define _BOWWEAPON_CLASS_

#include "Combat/Weapons/Weapon.hpp"

class BowWeapon : public Weapon {
private:
public:
    BowWeapon(int damage, int range, Vector2f projectileSize, int rateOfFire, const std::string& spriteLocation);
    virtual ~BowWeapon() { }
    virtual Projectile* Use(Vector2f dir, Vector2f origin);
};
#endif