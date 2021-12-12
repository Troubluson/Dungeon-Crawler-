#pragma once

#ifndef _WALL_PATROL_MONSTER_CLASS_
#define _WALL_PATROL_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "monster.hpp"

/**
 * @brief WallPatrolMonster walks along the walls of the room patroling. Then when the player is in its range it shoots projectiles towards it.
 *
 */
class WallPatrolMonster : public Monster {
public:
    WallPatrolMonster(PlayerPS player, float xPos, float yPos);
    WallPatrolMonster(PlayerPS player, sf::Vector2f pos);
    ~WallPatrolMonster();

    virtual std::list<ProjectileUP> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    int currentDir_ = 1;
    void changeDirection();
};

#endif