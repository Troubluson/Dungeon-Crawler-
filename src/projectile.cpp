#include "projectile.hpp"

Projectile::Projectile() {
  initVariables();
  initSprite();
}

Projectile::~Projectile() {}

void Projectile::Update(float dt) { MoveRight(dt); }

void Projectile::initSprite() {
  if (texture_.loadFromFile("content/squidman.png")) {
    sprite_.setTexture(texture_);
    sprite_.setScale(sf::Vector2f(1, 1));
  }
}

void Projectile::initVariables() {}