#pragma once

#ifndef _YELLOWPOTION_CLASS_
#define _YELLOWPOTION_CLASS_
#include "Actors/player.hpp"
#include "Potion.hpp"

class YellowPotion : public Potion {
public:
    YellowPotion(sf::Vector2f pos);
};

#endif