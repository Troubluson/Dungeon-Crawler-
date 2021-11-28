#include "Combat/Projectile.hpp"

namespace {
const std::string PROJECTILE_SPRITE = "content/sprites/projectile.png";
}

Projectile::Projectile(sf::Sprite& sprite, sf::Vector2f pos, bool penetrates)
    : Entity(sprite, pos.x, pos.y)
    , penetrates_(penetrates)
{
    initVariables();
}

bool Projectile::move(float dt, float x, float y)
{
    float xMovement = (x / (std::abs(x) + std::abs(y))) * projectileSpeed_;
    float yMovement = (y / (std::abs(x) + std::abs(y))) * projectileSpeed_;
    xMovement *= dt;
    yMovement *= dt;
    pos_.x += xMovement;
    pos_.y += yMovement;
    sprite_.setPosition(pos_);
    return true;
}

void Projectile::Update(float dt)
{
    timeExisted_ += dt;
    float distanceTravelledSquared = (std::abs(startPos_.x - pos_.x) + std::abs(startPos_.y - pos_.y));
    if (distanceTravelledSquared > distanceLifeSpanSquared_) {
        Kill();
    }
    move(dt, direction_.x, direction_.y);
}

void Projectile::initVariables()
{
    alive_ = true;
    timeExisted_ = 0;
    startPos_ = GetPos();
}

// Setters
void Projectile::SetDamage(int damage) { damage_ = damage; }
void Projectile::SetDirection(sf::Vector2f direction) { direction_ = direction; }
void Projectile::SetType(Projectile::Type type) { type_ = type; }
void Projectile::SetTimeLifeSpan(float timeLifeSpan) { timeLifeSpan_ = timeLifeSpan; }
void Projectile::SetDistanceLifeSpan(float distanceLifeSpan) { distanceLifeSpanSquared_ = distanceLifeSpan * distanceLifeSpan; }
void Projectile::SetProjectileSpeed(float projectileSpeed) { projectileSpeed_ = projectileSpeed; }
