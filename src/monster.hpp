#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "character.hpp"

class Monster : public Character {
public:
    Monster(sf::Vector2f);

    void Move();
};

#endif