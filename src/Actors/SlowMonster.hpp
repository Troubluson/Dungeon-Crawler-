#pragma once

#ifndef _SLOW_MONSTER_CLASS_
#define _SLOW_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class SlowMonster : public Monster {
public:
    SlowMonster(Player* player, float xPos, float yPos);
    SlowMonster(Player* player, sf::Vector2f pos);
    ~SlowMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    sf::Clock cooldown_;
};

#endif