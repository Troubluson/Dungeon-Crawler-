#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "character.hpp"

class Monster : public Character {
public:
    Monster(float xPos, float yPos);

    void Move(float dt);
};

#endif