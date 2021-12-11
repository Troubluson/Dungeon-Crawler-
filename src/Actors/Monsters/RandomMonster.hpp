#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "monster.hpp"

class RandomMonster : public Monster {
public:
    RandomMonster(PlayerPS player, float xPos, float yPos);
    RandomMonster(PlayerPS player, sf::Vector2f pos);
    ~RandomMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

private:
    int currentDir_;
    float durationUntilTurn = 3.0f;
    float elapsedTurnTime = 0.0f;
};

#endif