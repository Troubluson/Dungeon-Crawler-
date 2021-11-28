#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "Actors/character.hpp"

class Monster : public Character {
public:
    Monster(float xPos, float yPos);
    Monster(sf::Vector2f pos);
    ~Monster();
    void Move(float dt);
};

#endif