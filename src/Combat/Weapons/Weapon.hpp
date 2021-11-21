#pragma once
#ifndef _WEAPON_CLASS_
#define _WEAPON_CLASS_

#include "../../Actors/player.hpp"
#include "../PowerUps/PowerUp.hpp"
#include "../projectile.hpp"
#include "SpriteHelper.hpp"

using namespace std;
using namespace sf;
class Player; // to fix problem of ciruclar dependency, which is pretty bad but I don't see a way around it
class Weapon {
protected:
    Player* owner_ = nullptr;
    int damage_;
    int range_;
    Vector2f projectileSize_;
    bool penetrates_ = false;
    const int maxPowerUps = 3;
    int getPowerUpCount();
    Sprite sprite_;
    vector<PowerUp*> powerUps_;

public:
    Weapon(int damage, int range, Vector2f projectileSize, const std::string& spriteLocation);
    virtual ~Weapon() {};
    virtual void Use(Vector2f dir) = 0;
    virtual void Animate() = 0;
    void AddPowerUp(PowerUp* up);
    void EquipFor(Player* owner);
};
#endif