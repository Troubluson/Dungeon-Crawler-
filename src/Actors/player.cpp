#include "Actors/player.hpp"

namespace {
const std::string PLAYER_DEATH_SPRITE = "content/sprites/characters/deathanimation.png";
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
    if (hasAnimation_) {
        if (IsAlive()) {
            if (oldPos_.x == pos_.x && oldPos_.y == pos_.y) {
                Idle();
            }
            animationHandler_.getAnimation()->Update(dt);
            animationHandler_.getAnimation()->AnimationToSprite(sprite_);
        } else {
            Dead();
            if (deadAnimationPlayed == false) {
                animationHandler_.getAnimation()->Update(dt);
                animationHandler_.getAnimation()->AnimationToSprite(sprite_);
                dt_time += dt;
                std::cout << dt_time << " " << dt << std::endl;
                if (dt_time > 0.73) {
                    deadAnimationPlayed = true;
                };
            }
        }
    }

    generalUpdate(dt);

    updateDashCooldown(dt);

    if (IsDashing) {
        currentSpeed_ = dashSpeed_;
    } else {
        currentSpeed_ = defaultSpeed_;
    }
}

void Player::Dash()
{
    if (CanDash) {
        IsDashing = true;
        dashDurationLeft_ = dashDurationLength_;
        ResetDashCooldown();
    }
}

void Player::initVariables()
{
    dashCooldownLength_ = 1.0f;
    dashCooldownLeft_ = 0.0f;
    CanDash = true;
    IsDashing = false;
    dashDurationLength_ = 0.25f;
    dashDurationLeft_ = 0.0f;
    SetNormalSpeed(300.0f);
    dashSpeed_ = defaultSpeed_ * 3;

    characterProjectileType_ = Projectile::Type::PlayerProjectile;
}

void Player::ResetDashCooldown()
{
    dashCooldownLeft_ = dashCooldownLength_;
    CanDash = false;
}

void Player::updateDashCooldown(float dt)
{
    dashCooldownLeft_ = std::max(0.0f, dashCooldownLeft_ - dt);
    if (dashCooldownLeft_ <= 0.0f) {
        CanDash = true;
    }

    if (IsDashing) {
        dashDurationLeft_ -= dt;
    }
    if (dashDurationLeft_ <= 0) {
        IsDashing = false;
    }
}

std::list<Projectile*> Player::Attack(sf::Vector2f aimPos)
{
    if (!CanAttack || !HasWeapon()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(aimPos);
}