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

void Player::Update(float dt)
{
    if (hasAnimation_) {
        if (IsAlive()) {
            deadAnimationPlayed = false;
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
    if (IsAlive()) {
        generalUpdate(dt);

        updateDashCooldown(dt);
    }

    if (IsDashing) {
        currentSpeed_ = dashSpeed_;
    } else {
        currentSpeed_ = defaultSpeed_;
    }
}

void Player::Dash()
{
    if (CanDash) {
        if (dashesBoosted_ > 0) {
            dashCurrentDurationLength_ = dashDefaultDurationLength_ * dashLengthBoostModifier;
            dashesBoosted_ -= 1;
        }
        IsDashing = true;
        dashDurationLeft_ = dashCurrentDurationLength_;
        ResetDashCooldown();
    }
}

void Player::initVariables()
{
    dashCooldownLength_ = 1.0f;
    dashCooldownLeft_ = 0.0f;
    CanDash = true;
    IsDashing = false;
    dashDefaultDurationLength_ = 0.25f;
    dashCurrentDurationLength_ = dashDefaultDurationLength_;
    dashDurationLeft_ = 0.0f;
    SetNormalSpeed(300.0f);
    dashSpeed_ = defaultSpeed_ * 3;

    attacksBoosted_ = 0;
    dashesBoosted_ = 0;

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
        dashCurrentDurationLength_ = dashDefaultDurationLength_;
        IsDashing = false;
    }
}

std::list<ProjectileUP> Player::Attack(sf::Vector2f aimPos)
{
    if (!CanAttack || !HasWeapon() || !IsAlive()) {
        return emptyList();
    }

    ResetAttackCooldown();

    if (attacksBoosted_ > 0) {
        weapon_->BoostDamageValue();
        attacksBoosted_ -= 1;
    }

    auto res = shotProjectileList(aimPos);
    weapon_->UnBoostDamageValue();
    return res;
}

void Player::AddPotion(Potion* potion)
{
    inventory_.push_back(potion);
}

void Player::UsePotion(const std::string& colour)
{
    bool found = false;
    auto it = inventory_.begin();
    while (it != inventory_.end() && !found) {
        if ((*it)->GetColour() == colour) {
            if (colour == "violet") {
                attacksBoosted_ += 10;
            } else if (colour == "yellow") {
                dashesBoosted_ += 3;
            } else {
                Heal((*it)->GetHealthIncrease());
            }
            it = inventory_.erase(it);
            found = true;
        } else {
            ++it;
        }
    }
}

std::vector<Potion*> Player::GetInventory() const
{
    return inventory_;
}