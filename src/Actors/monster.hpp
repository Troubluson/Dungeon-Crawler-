#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "character.hpp"
#include "player.hpp"

class Monster : public Character {
public:
    Monster(Player* player, float xPos, float yPos);
    Monster(Player* player, sf::Vector2f pos);
    ~Monster();

    Player& GetPlayer() const;
    virtual void Update(float dt);
    virtual void Move(float dt) = 0;
    virtual void MonsterAttack() = 0;

private:
    Player* player_;
};

#endif