#pragma once

#ifndef _SnipingMonster_CLASS_
#define _SnipingMonster_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class SnipingMonster : public Monster {
public:
    SnipingMonster(Player* player, float xPos, float yPos, const std::string& spriteFile);
    SnipingMonster(Player* player, sf::Vector2f pos, const std::string& spriteFile);
    ~SnipingMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);
};

#endif