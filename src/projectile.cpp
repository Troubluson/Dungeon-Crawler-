#include "projectile.hpp"

namespace {
const std::string PROJECTILE_SPRITE = "content/sprites/projectile.png";
}

Projectile::Projectile(float x, float y)
    : Entity(PROJECTILE_SPRITE, x, y, 1)
{
    initVariables();
}

void Projectile::Update(float dt) { Move(dt, direction_.x, direction_.y); }

void Projectile::initVariables() { }

Projectile::Type Projectile::GetType() { return type_; }

void Projectile::SetDamage(int damage)
{
    damage_ = damage;
}

void Projectile::SetDirection(sf::Vector2f direction)
{
    direction_ = direction;
}

void Projectile::SetType(Projectile::Type type)
{
    type_ = type;
}