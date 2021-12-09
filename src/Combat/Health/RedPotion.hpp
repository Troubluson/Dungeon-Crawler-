#pragma once

#ifndef _REDPOTION_CLASS_
#define _REDPOTION_CLASS_
#include "Actors/player.hpp"
#include "Potion.hpp"

class RedPotion : public Potion {
public:
    RedPotion(sf::Vector2f pos);
};

#endif