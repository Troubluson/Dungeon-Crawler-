#pragma once

#ifndef _HEALTHPOTION_CLASS_
#define _HEALTHPOTION_CLASS_
#include "Actors/player.hpp"
#include "entity.hpp"

class HealthPotion : public Entity {
public:
    HealthPotion(sf::Vector2f pos, sf::Vector2f spriteDims, int healthIncrease);

    bool IsCollected();

    int HealthIncrease(sf::Vector2f pos);

private:
    int healthIncrease_;
    bool collected_;
};

#endif