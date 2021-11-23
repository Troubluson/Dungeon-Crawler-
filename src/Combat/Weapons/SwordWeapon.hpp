#pragma once
#ifndef _SWORDWEAPON_CLASS_
#define _SWORDWEAPON_CLASS_

#include "Weapon.hpp"

class SwordWeapon : public Weapon {
private:
public:
    SwordWeapon(int damage, int range, Vector2f projectileSize, const std::string& spriteLocation);
    virtual ~SwordWeapon() { }
    virtual list<Projectile*> Use(Vector2f dir, Vector2f origin);
};
#endif