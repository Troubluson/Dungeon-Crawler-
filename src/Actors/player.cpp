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
    if (hasAnimation_) {
        if (oldPos_.x == pos_.x && oldPos_.y == pos_.y) {
            Idle();
        }
        animationHandler_.getAnimation()->Update(dt);
        animationHandler_.getAnimation()->AnimationToSprite(sprite_);
    }

    generalUpdate(dt);

    updateDashCooldown(dt);

    if (IsDashing) {
        currentSpeed_ = dashSpeed;
    } else {
        currentSpeed_ = normalSpeed_;
    }
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

    dashCooldownLength = 1.0f;
    dashCooldownLeft = 0.0f;
    CanDash = true;
    IsDashing = false;
    dashDurationLength = 0.25f;
    dashDurationLeft = 0.0f;
    normalSpeed_ = 300.0f;
    dashSpeed = normalSpeed_ * 3;

    characterProjectileType = Projectile::Type::PlayerProjectile;
}

void Player::ResetDashCooldown()
{
    dashCooldownLeft = dashCooldownLength;
    CanDash = false;
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

std::list<Projectile*> Player::Attack(sf::Vector2f aimPos)
{
    if (!CanAttack || !HasWeapon()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(aimPos);
}

void Player::AddPotion(Potion* potion)
{
    inventory_.push_back(potion);
    std::cout << "picked up a potion" << std::endl;
}

void Player::UsePotion(const std::string& colour)
{
    bool found = false;
    auto it = inventory_.begin();
    while (it != inventory_.end() && !found) {
        if ((*it)->GetColour() == colour) {
            Heal((*it)->GetHealthIncrease());
            std::cout << "drinking potion" << std::endl;
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