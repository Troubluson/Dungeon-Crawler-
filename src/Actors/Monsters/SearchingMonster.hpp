#pragma once

#ifndef _SEARCHING_MONSTER_CLASS_
#define _SEARCHING_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "monster.hpp"
#include "Actors/player.hpp"

class SearchingMonster : public Monster {
public:
    SearchingMonster(Character* player, float xPos, float yPos);
    SearchingMonster(Character* player, sf::Vector2f pos);
    ~SearchingMonster();
    virtual bool Move(float dt);
    void MonsterAttack();

private:
    sf::Clock cooldown_;
};

#endif