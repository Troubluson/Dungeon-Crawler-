#pragma once

#ifndef _RANDOM_MONSTER_CLASS_
#define _RANDOM_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "monster.hpp"

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
    const std::string name = "Randy";
};

#endif