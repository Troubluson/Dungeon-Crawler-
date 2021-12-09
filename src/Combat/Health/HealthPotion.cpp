#include "HealthPotion.hpp"

HealthPotion::HealthPotion(sf::Vector2f pos, sf::Vector2f spriteDims, int healthIncrease)
    : Entity("content/sprites/potions/green_potion.png", pos, spriteDims)
    , healthIncrease_(healthIncrease)
    , collected_(false)
{
}

bool HealthPotion::IsCollected()
{
    return collected_;
}

void HealthPotion::Use(Character* character)
{
    character->Heal(healthIncrease_);
    collected_ = true;
}