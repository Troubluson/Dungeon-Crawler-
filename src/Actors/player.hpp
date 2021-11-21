#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "../Combat/Weapons/Weapon.hpp"
#include "character.hpp"

class Player : public Character {
public:
    Player();
    ~Player() {};
    int GetHitPoints() const;

    int Attack(Character ch);
    void Equip(Weapon* weapon);

private:
    Weapon* weapon_;
};

#endif