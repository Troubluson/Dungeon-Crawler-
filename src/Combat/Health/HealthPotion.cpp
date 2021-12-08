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

int HealthPotion::HealthIncrease(sf::Vector2f pos)
{
    float distance = (GetPos() - pos).x * (GetPos() - pos).x + (GetPos() - pos).y * (GetPos() - pos).y;
    //std::cout << distance << std::endl;
    if (distance < 20) {
        collected_ = true;
        return healthIncrease_;
    } else {
        return 0;
    }
}