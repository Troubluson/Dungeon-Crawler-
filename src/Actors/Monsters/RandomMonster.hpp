#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "monster.hpp"

class RandomMonster : public Monster {
public:
    RandomMonster(Character* player, float xPos, float yPos);
    RandomMonster(Character* player, sf::Vector2f pos);
    ~RandomMonster();
    virtual bool Move(float dt);
    virtual void MonsterAttack();

private:
    sf::Clock clock_;
    int currentDir_;
};

#endif