#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class RandomMonster : public Monster {
public:
    RandomMonster(Player* player, float xPos, float yPos);
    RandomMonster(Player* player, sf::Vector2f pos);
    ~RandomMonster();
    virtual bool Move(float dt);
    virtual void MonsterAttack();

private:
    sf::Clock clock_;
    int currentDir_;
};

#endif