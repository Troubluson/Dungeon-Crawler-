#include "projectile.hpp"

namespace {
const std::string PROJECTILE_SPRITE = "content/sprites/projectile.png";
}

Projectile::Projectile(float x, float y)
    : Entity(PROJECTILE_SPRITE, x, y, 1)
{
    initVariables();
    timeExisted_ = 0;
}

bool Projectile::move(float dt, float x, float y)
{
    float xMovement = (x / (std::abs(x) + std::abs(y))) * projectileSpeed_;
    float yMovement = (y / (std::abs(x) + std::abs(y))) * projectileSpeed_;
    xMovement *= dt;
    yMovement *= dt;
    xPos_ += xMovement;
    yPos_ += yMovement;
    sprite_.setPosition(xPos_, yPos_);
    return true;
}

void Projectile::Update(float dt)
{
    timeExisted_ += dt;
    move(dt, direction_.x, direction_.y);
}

void Projectile::initVariables() { }

//Getters
int Projectile::GetDamage() { return damage_; }
Projectile::Type Projectile::GetType() { return type_; }
sf::Vector2f Projectile::GetDirection() { return direction_; }
float Projectile::GetTimeExisted() { return timeExisted_; }
float Projectile::GetTimeLifeSpan() { return timeLifeSpan_; }
float Projectile::GetProjectileSpeed() { return projectileSpeed_; }

//Setters
void Projectile::SetDamage(int damage) { damage_ = damage; }
void Projectile::SetDirection(sf::Vector2f direction) { direction_ = direction; }
void Projectile::SetType(Projectile::Type type) { type_ = type; }
void Projectile::SetTimeLifeSpan(float timeLifeSpan) { timeLifeSpan_ = timeLifeSpan; }
void Projectile::SetProjectileSpeed(float projectileSpeed) { projectileSpeed_ = projectileSpeed; }