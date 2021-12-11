
#include "Combat/Weapons/Weapon.hpp"

Weapon::Weapon(int damage, int range, int rateOfFire, float projectileSpeed, Vector2f projectileSize, const std::string& spriteLocation)
    : damage_(damage)
    , range_(range)
    , projectileSpeed_(projectileSpeed)
    , projectileSize_(projectileSize)
    , speed_(projectileSpeed)
    , powerUps_(vector<PowerUp*>())
{
    spritehelper::CreateSpriteFrom(spriteLocation, projectileSize, sprite_, texture_);
    cooldown_ = 60.0f / rateOfFire;
}

void Weapon::AddPowerUp(PowerUp* up)
{
    if (getPowerUpCount() < maxPowerUps) {
        powerUps_.push_back(up);
    } else {
        // TODO: prompt the user to replace a existing powerUp
    }
}

int Weapon::getPowerUpCount() { return powerUps_.size(); }

void Weapon::SetTextureRect(sf::IntRect rect)
{
    sprite_.setTextureRect(rect);
}