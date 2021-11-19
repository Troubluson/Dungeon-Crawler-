#include "projectile.hpp"

namespace {
const std::string PROJECTILE_SPRITE = "content/sprites/projectile.png";
}

Projectile::Projectile(Type type, sf::Vector2f direction, float x, float y)
    : Entity(PROJECTILE_SPRITE, x, y, 1)
{
    initVariables();
    type_ = type;
    direction_ = direction;
}

Projectile::Projectile(float x, float y)
    : Entity(PROJECTILE_SPRITE, x, y, 1)
{
    initVariables();
    sprite_.setPosition(x, y);
}

void Projectile::Update(float dt) { MoveRight(dt); }

void Projectile::initVariables() { }

Projectile::Type Projectile::GetType() { return type_; }