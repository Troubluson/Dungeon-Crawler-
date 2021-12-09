#pragma once

#ifndef _POTION_CLASS_
#define _POTION_CLASS_
#include "Actors/player.hpp"
#include "entity.hpp"

class Potion : public Entity {
public:
    Potion(const std::string& spritefile, sf::Vector2f pos, int healthIncrease);

    virtual ~Potion() {};

    bool IsCollected();

    void Use(Character* character);

protected:
    int healthIncrease_;
    bool collected_;
};

#endif