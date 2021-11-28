#include "character.hpp"
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

void Character::initVariables()
{
    alive_ = true;
    hitpoints_ = 50;
}

bool Character::MoveLeft(float dt)
{
    pos_.x -= speed_ * dt;
    currentAnimation = AnimationIndex::AnimationLeft;
    return true;
}

bool Character::MoveRight(float dt)
{
    pos_.x += speed_ * dt;
    currentAnimation = AnimationIndex::AnimationRight;
    return true;
}

bool Character::MoveDown(float dt)
{
    pos_.y += speed_ * dt;
    currentAnimation = AnimationIndex::AnimationDown;
    return true;
}

bool Character::MoveUp(float dt)
{
    pos_.y -= speed_ * dt;
    currentAnimation = AnimationIndex::AnimationUp;
    return true;
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
    std::cout << hitpoints_ << std::endl;
}

bool Character::IsAlive() { return alive_; }

bool Character::Idle()
{
    currentAnimation = AnimationIndex::AnimationIdle;
    return true;
}