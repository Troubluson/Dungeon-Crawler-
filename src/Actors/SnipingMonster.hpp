#pragma once

#ifndef _SNIPING_MONSTER_CLASS_
#define _SNIPING_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class SnipingMonster : public Monster {
public:
    SnipingMonster(Player* player, float xPos, float yPos);
    SnipingMonster(Player* player, sf::Vector2f pos);
    ~SnipingMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
};

#endif