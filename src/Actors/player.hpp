#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "Actors/character.hpp"
#include "Combat/Weapons/Weapon.hpp"

class Weapon;
class Player : public Character {
public:
    Player();
    ~Player() {};
    int GetHitPoints() const;

    void Attack(sf::Vector2f mousePos, std::list<Projectile*>& worldProjectiles);
    void Equip(Weapon* weapon);

private:
    Weapon* weapon_;
};

#endif