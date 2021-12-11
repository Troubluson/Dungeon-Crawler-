#include "Potion.hpp"

Potion::Potion(const std::string& spritefile, sf::Vector2f pos, int healthIncrease, const std::string& colour)
    : Entity(spritefile, pos, sf::Vector2f(0.7, 0.7))
    , healthIncrease_(healthIncrease)
    , colour_(colour)
{
}

const std::string& Potion::GetColour() const
{
    return colour_;
}

int Potion::GetHealthIncrease() const
{
    return healthIncrease_;
}