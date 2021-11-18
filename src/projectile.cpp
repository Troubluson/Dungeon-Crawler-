#include "projectile.hpp"

namespace {
const std::string PROJECTILE_SPRITE = "content/sprites/squidman.png";
}

Projectile::Projectile(float x, float y)
    : Entity(PROJECTILE_SPRITE, x, y)
{
    initVariables();
    sprite_.setPosition(x, y);
}

Projectile::~Projectile() { }

void Projectile::Update(float dt) { MoveRight(dt); }

void Projectile::initVariables() { }