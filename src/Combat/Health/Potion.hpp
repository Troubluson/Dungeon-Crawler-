#pragma once

#ifndef _POTION_CLASS_
#define _POTION_CLASS_
#include "entity.hpp"

class Potion : public Entity {
public:
    Potion(const std::string& spritefile, sf::Vector2f pos, int healthIncrease, const std::string& colour);

    virtual ~Potion() {};

    /**
     * @brief Get the Colour of the potion
     *
     * @return const refrence to a string with the color
     */
    const std::string& GetColour() const;

    /**
     * @brief Get the Healing effect of the potion.
     *
     * @return int
     */
    int GetHealthIncrease() const;

protected:
    int healthIncrease_;
    std::string colour_;
};

#endif