
#include "Combat/Weapons/Weapon.hpp"

Weapon::Weapon(int damage, int range, Vector2f projectileSize, const std::string& spriteLocation)
    : damage_(damage)
    , range_(range)
    , projectileSize_(projectileSize)
    , powerUps_(vector<PowerUp*>())
{
    spritehelper::CreateSpriteFrom(spriteLocation, projectileSize, sprite_, texture_);
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