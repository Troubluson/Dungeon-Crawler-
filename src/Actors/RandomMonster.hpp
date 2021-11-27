#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class RandomMonster : public Monster {
public:
    RandomMonster(float xPos, float yPos);
    RandomMonster(sf::Vector2f pos);
    ~RandomMonster();
    virtual void Move(float dt);

private:
    sf::Clock clock_;
    int currentDir_;
};

#endif