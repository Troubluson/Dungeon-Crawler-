#pragma once

#ifndef _HEALTHPOTIONS_CLASS_
#define _HEALTHPOTIONS_CLASS_
#include "Actors/player.hpp"
#include "Potion.hpp"

/**
 * @brief A green potion. Takes a position as parameter and the colour and healing effect is set automatically.
 *
 */
class GreenPotion : public Potion {
public:
    GreenPotion(sf::Vector2f pos)
        : Potion("content/sprites/potions/green_potion.png", pos, 10, "green")
    {
    }
};

/**
 * @brief A red potion. Takes a position as parameter and the colour and healing effect is set automatically.
 *
 */
class RedPotion : public Potion {
public:
    RedPotion(sf::Vector2f pos)
        : Potion("content/sprites/potions/red_potion.png", pos, 5, "red")
    {
    }
};

/**
 * @brief A yellow potion. Takes a position as parameter and the colour and healing effect is set automatically.
 *
 */
class YellowPotion : public Potion {
public:
    YellowPotion(sf::Vector2f pos)
        : Potion("content/sprites/potions/yellow_potion.png", pos, 15, "yellow")
    {
    }
};

/**
 * @brief A violet potion. Takes a position as parameter and the colour and healing effect is set automatically.
 *
 */
class VioletPotion : public Potion {
public:
    VioletPotion(sf::Vector2f pos)
        : Potion("content/sprites/potions/violet_potion.png", pos, 50, "violet")
    {
    }
};

#endif
