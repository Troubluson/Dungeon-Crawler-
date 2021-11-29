#include "Actors/character.hpp"
#define C_PIXELS 64
#define C_SCALE 2

Character::Character(const std::string& filename, sf::Vector2f pos, bool animated)
    : Entity(filename, pos, sf::Vector2f(C_SCALE, C_SCALE))
    , hasAnimation_(animated)
    , oldPos_(pos)
{
    initVariables();
    if (hasAnimation_) {
        sprite_.setTextureRect({ 0, 0, C_PIXELS, C_PIXELS });
        sprite_.setScale(sf::Vector2f(2, 2));
        Animations[int(AnimationIndex::AnimationUp)] = new Animation(C_PIXELS, 0, C_PIXELS, C_PIXELS, filename);
        Animations[int(AnimationIndex::AnimationDown)] = new Animation(C_PIXELS, C_PIXELS * 4, C_PIXELS, C_PIXELS, filename);
        Animations[int(AnimationIndex::AnimationLeft)] = new Animation(C_PIXELS, C_PIXELS * 2, C_PIXELS, C_PIXELS, filename);
        Animations[int(AnimationIndex::AnimationRight)] = new Animation(C_PIXELS, C_PIXELS * 3, C_PIXELS, C_PIXELS, filename);
        Animations[int(AnimationIndex::AnimationIdle)] = new Animation(C_PIXELS, C_PIXELS, C_PIXELS, C_PIXELS, filename);
    }
}

Character::~Character() { }

void Character::UpdateCooldowns(float dt)
{
    updateAttackCooldown(dt);
    updateDashCooldown(dt);
    if (IsDashing) {
        currentSpeed_ = dashSpeed;
    } else {
        currentSpeed_ = normalSpeed_;
    }
}

float Character::clamp(float value, float low, float high)
{
    if (value < low) {
        value = low;
    }
    if (value > high) {
        value = high;
    }
    return value;
}

void Character::updateAttackCooldown(float dt)
{
    attackCooldownLeft = std::max(0.0f, attackCooldownLeft - dt);
    if (attackCooldownLeft <= 0.0f) {
        CanAttack = true;
    }
}

void Character::updateDashCooldown(float dt)
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

void Character::initVariables()
{
    alive_ = true;
    hitpoints_ = 50;
    currentSpeed_ = normalSpeed_;
    dashSpeed = 400.0f;

    attackCooldownLength = 5.0f;
    attackCooldownLeft = 0.0f;
    CanAttack = true;
    dashCooldownLength = 5.0f;
    dashCooldownLeft = 0.0f;
    CanDash = true;

    IsDashing = false;
    dashDurationLength = 2.0f;
    dashDurationLeft = dashDurationLength;
}

bool Character::MoveLeft(float dt)
{
    pos_.x -= currentSpeed_ * dt;
    currentAnimation = AnimationIndex::AnimationLeft;
    return true;
}

bool Character::MoveRight(float dt)
{
    pos_.x += currentSpeed_ * dt;
    currentAnimation = AnimationIndex::AnimationRight;
    return true;
}

bool Character::MoveDown(float dt)
{
    pos_.y += currentSpeed_ * dt;
    currentAnimation = AnimationIndex::AnimationDown;
    return true;
}

bool Character::MoveUp(float dt)
{
    pos_.y -= currentSpeed_ * dt;
    currentAnimation = AnimationIndex::AnimationUp;
    return true;
}

void Character::Dash()
{
    if (CanDash) {
        IsDashing = true;
        dashDurationLeft = dashDurationLength;
        ResetDashCooldown();
    }
}

sf::Vector2f Character::GetSpriteCenter()
{
    auto spriteOrigin = GetPos();
    auto localSpriteBounds = sprite_.getLocalBounds();
    auto spriteScale = sprite_.getScale();
    spriteOrigin.x += 1.0f / 2 * localSpriteBounds.width * spriteScale.x;
    spriteOrigin.y += 1.0f / 2 * localSpriteBounds.height * spriteScale.y;
    return spriteOrigin;
}

void Character::TakeDamage(int value)
{
    hitpoints_ -= value;
}

void Character::ResetAttackCooldown()
{
    attackCooldownLeft = attackCooldownLength;
    CanAttack = false;
}

void Character::ResetDashCooldown()
{
    dashCooldownLeft = dashCooldownLength;
    CanDash = false;
}

bool Character::IsAlive() { return alive_; }

bool Character::Idle()
{
    currentAnimation = AnimationIndex::AnimationIdle;
    return true;
}