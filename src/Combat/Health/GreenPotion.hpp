#pragma once

#ifndef _GREENPOTION_CLASS_
#define _GREENPOTION_CLASS_
#include "Actors/player.hpp"
#include "Potion.hpp"

class GreenPotion : public Potion {
public:
    GreenPotion(sf::Vector2f pos);
};

#endif