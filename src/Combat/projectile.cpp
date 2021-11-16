#include "projectile.hpp"

Projectile::Projectile(float x, float y) {
  initVariables();
  initSprite("content/sfml.png");
  sprite_.setPosition(x, y);
}

Projectile::~Projectile() {}

void Projectile::Update(float dt) { MoveRight(dt); }

void Projectile::initVariables() {}