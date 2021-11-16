
#include "Weapon.hpp"

#include "Direction.hpp"

void Weapon::AddPowerUp(PowerUp* up) {
  if (getPowerUpCount() < maxPowerUps) {
    powerUps_.push_back(up);
  } else {
    // TODO: prompt the user to replace a existing powerUp
  }
}

int Weapon::getPowerUpCount() { return powerUps_.size(); }