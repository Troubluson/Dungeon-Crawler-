#include "Actors/player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/sprites/characters/SpriteSheet.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, sf::Vector2f(200, 200), true)
{
    initVariables();
}

int Player::GetHitPoints() const { return hitpoints_; }

void Player::Update(float dt)
{
    sprite_.setPosition(pos_);
    if (hitpoints_ <= 0) {
        alive_ = false;
    }

    if (hasAnimation_) {
        if (oldPos_ == pos_) {
            Idle();
        }
        Animations[int(currentAnimation)]->Update(dt);
        Animations[int(currentAnimation)]->AnimationToSprite(sprite_);
    }

    oldPos_ = pos_;

    updateAttackCooldown(dt);
    updateDashCooldown(dt);

    if (IsDashing) {
        currentSpeed_ = dashSpeed;
    } else {
        currentSpeed_ = normalSpeed_;
    }
}

Projectile* Player::FireProjectile(sf::Vector2f aimPosition)
{
    if (weapon_ == nullptr) {
        return nullptr;
    }
    if (!CanAttack) {
        return nullptr;
    }
    ResetAttackCooldown();
    auto spriteCenter = GetSpriteCenter();
    auto direction = aimPosition - spriteCenter;
    auto newProjectile = weapon_->Use(direction, spriteCenter);
    newProjectile->SetType(Projectile::Type::PlayerProjectile);
    return newProjectile;
}

void Player::Equip(Weapon* weapon)
{
    weapon_ = weapon;
    attackCooldownLength = weapon->GetAttackCooldown();
}

void Player::Dash()
{
    if (CanDash) {
        IsDashing = true;
        dashDurationLeft = dashDurationLength;
        ResetDashCooldown();
    }
}

void Player::initVariables()
{
    normalSpeed_ = 200.0f;
    dashSpeed = 400.0f;

    attackCooldownLength = 1.66f;
    attackCooldownLeft = 0.0f;
    CanAttack = true;
    dashCooldownLength = 1.0f;
    dashCooldownLeft = 0.0f;
    CanDash = true;

    IsDashing = false;
    dashDurationLength = 1.0f;
    dashDurationLeft = dashDurationLength;
}

void Player::ResetAttackCooldown()
{
    attackCooldownLeft = attackCooldownLength;
    CanAttack = false;
}

void Player::ResetDashCooldown()
{
    dashCooldownLeft = dashCooldownLength;
    CanDash = false;
}

void Player::updateAttackCooldown(float dt)
{
    attackCooldownLeft = std::max(0.0f, attackCooldownLeft - dt);
    if (attackCooldownLeft <= 0.0f) {
        CanAttack = true;
    }
}

void Player::updateDashCooldown(float dt)
{
    dashCooldownLeft = std::max(0.0f, dashCooldownLeft - dt);
    if (dashCooldownLeft <= 0.0f) {
        CanDash = true;
    }

    if (IsDashing) {
        dashDurationLeft -= dt;
    }
    if (dashDurationLeft <= 0) {
        IsDashing = false;
    }
}