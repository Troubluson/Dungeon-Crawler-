#pragma once

#ifndef _WALL_PATROL_MONSTER_CLASS_
#define _WALL_PATROL_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "monster.hpp"

class WallPatrolMonster : public Monster {
public:
    WallPatrolMonster(Player& player, float xPos, float yPos);
    WallPatrolMonster(Player& player, sf::Vector2f pos);
    ~WallPatrolMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    int currentDir_ = 1;
    void changeDirection();
};

#endif