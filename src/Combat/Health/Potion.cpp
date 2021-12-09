#include "Potion.hpp"

Potion::Potion(const std::string& spritefile, sf::Vector2f pos, int healthIncrease)
    : Entity(spritefile, pos, sf::Vector2f(0.7, 0.7))
    , healthIncrease_(healthIncrease)
    , collected_(false)
{
}

bool Potion::IsCollected()
{
    return collected_;
}

void Potion::Use(Character* character)
{
    character->Heal(healthIncrease_);
    collected_ = true;
}