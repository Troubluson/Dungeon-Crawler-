#include "player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/spritesheet.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, sf::Vector2f(200, 200), true)
{
}

int Player::GetHitPoints() const { return hitpoints_; }

void Player::Attack(sf::Vector2f mousePosition, std::list<Projectile*>& projectiles)
{
    if (weapon_ == nullptr) {
        return;
    }
    auto spriteCenter = GetSpriteCenter();
    auto direction = mousePosition - spriteCenter;
    auto newProjectiles = weapon_->Use(direction, spriteCenter);
    projectiles.splice(projectiles.end(), newProjectiles); // moves new projectiles to the back of projectiles_
}

void Player::Equip(Weapon* weapon)
{
    weapon_ = weapon;
}