#pragma once

#ifndef _SNIPING_MONSTER_CLASS_
#define _SNIPING_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/BowWeapon.hpp"
#include "monster.hpp"

/**
 * @brief SnipingMonster never moves but shoots projectile towards the player with a really big range.
 *
 */
class SnipingMonster : public Monster {
public:
    SnipingMonster(PlayerPS player, float xPos, float yPos);
    SnipingMonster(PlayerPS player, sf::Vector2f pos);
    ~SnipingMonster();

    virtual std::list<ProjectileUP> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
};

#endif