#pragma once

#ifndef _SEARCHING_MONSTER_CLASS_
#define _SEARCHING_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class SearchingMonster : public Monster {
public:
    SearchingMonster(Player* player, float xPos, float yPos);
    SearchingMonster(Player* player, sf::Vector2f pos);
    ~SearchingMonster();
    virtual void Move(float dt);

private:
    Player* player_;
};

#endif