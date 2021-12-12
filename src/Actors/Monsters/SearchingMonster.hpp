#pragma once

#ifndef _SEARCHING_MONSTER_CLASS_
#define _SEARCHING_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "monster.hpp"

/**
 * @brief SearchingMonster is our only monster that does not shoot projectile but rather directly decreases the healthpoints of the player. It as its name says always walks towards the player
 *
 */
class SearchingMonster : public Monster {
public:
    SearchingMonster(PlayerPS player, float xPos, float yPos);
    SearchingMonster(PlayerPS player, sf::Vector2f pos);
    ~SearchingMonster();

    virtual std::list<ProjectileUP> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    sf::Clock cooldown_;
    std::string name_ = "Sir Chi";
};

#endif
