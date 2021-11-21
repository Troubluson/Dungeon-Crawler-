#include "player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/sprites/squidman.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, 0, 0)
{
}

/*void Player::Attack(sf::Vector2f dir, std::list<Projectile*>& projectiles)
{
}*/

void Player::Equip(Weapon* weapon)
{
    weapon_ = weapon;
    weapon_->EquipFor(this);
}