#pragma once

#ifndef _SEARCHING_MONSTER_CLASS_
#define _SEARCHING_MONSTER_CLASS_

#include "character.hpp"
#include "monster.hpp"
#include "player.hpp"

class SearchingMonster : public Monster {
public:
    SearchingMonster(Player* player, float xPos, float yPos, const std::string& spriteFile);
    SearchingMonster(Player* player, sf::Vector2f pos, const std::string& spriteFile);
    ~SearchingMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

private:
    sf::Clock cooldown_;
};

#endif