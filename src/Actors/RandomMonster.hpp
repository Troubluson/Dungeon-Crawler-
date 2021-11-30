#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class RandomMonster : public Monster {
public:
    RandomMonster(Player* player, float xPos, float yPos, const std::string& spriteFile);
    RandomMonster(Player* player, sf::Vector2f pos, const std::string& spriteFile);
    ~RandomMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

private:
    int currentDir_;
    float durationUntilTurn = 3.0f;
    float elapsedTurnTime = 0.0f;
};

#endif