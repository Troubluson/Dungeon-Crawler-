#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "monster.hpp"

class RandomMonster : public Monster {
public:
    RandomMonster(Player& player, float xPos, float yPos);
    RandomMonster(Player& player, sf::Vector2f pos);
    ~RandomMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    int currentDir_;
    float durationUntilTurn = 0.5f;
    float elapsedTurnTime = 0.0f;
};

#endif