#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "character.hpp"
#include "player.hpp"

class Monster : public Character {
public:
    Monster(float xPos, float yPos);
    Monster(sf::Vector2f pos);
    ~Monster();
    virtual void Move(float dt) = 0;
    virtual void MonsterAttack(Player& player) = 0;
};

#endif