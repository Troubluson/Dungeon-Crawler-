#pragma once

#ifndef _POTION_CLASS_
#define _POTION_CLASS_
#include "entity.hpp"

class Potion : public Entity {
public:
    Potion(const std::string& spritefile, sf::Vector2f pos, int healthIncrease, const std::string& colour);

    virtual ~Potion() {};

    const std::string& GetColour() const;
    int GetHealthIncrease() const;

protected:
    int healthIncrease_;
    std::string colour_;
};

#endif