#pragma once

#ifndef _SEARCHING_MONSTER_CLASS_
#define _SEARCHING_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "monster.hpp"

class SearchingMonster : public Monster {
public:
    SearchingMonster(Player& player, float xPos, float yPos);
    SearchingMonster(Player& player, sf::Vector2f pos);
    ~SearchingMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    sf::Clock cooldown_;
    std::string name = "Sir Chi";
};

#endif
