#pragma once

#ifndef _SLOW_MONSTER_CLASS_
#define _SLOW_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/BowWeapon.hpp"
#include "monster.hpp"

class SlowMonster : public Monster {
public:
    SlowMonster(Player& player, float xPos, float yPos);
    SlowMonster(Player& player, sf::Vector2f pos);
    ~SlowMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
};

#endif