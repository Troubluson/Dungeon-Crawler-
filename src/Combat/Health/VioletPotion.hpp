#pragma once

#ifndef _VIOLETPOTION_CLASS_
#define _VIOLETPOTION_CLASS_
#include "Actors/player.hpp"
#include "Potion.hpp"

class VioletPotion : public Potion {
public:
    VioletPotion(sf::Vector2f pos);
};

#endif