#include "Actors/character.hpp"
#include "utility/SpriteHelper.hpp"
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

void Character::Update(float dt)
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

const sf::Vector2f& Character::getOldPosition() const
{
    return oldPos_;
}

void Character::TakeDamage(int value)
{
    hitpoints_ -= value;
}

bool Character::IsAlive() { return alive_; }

bool Character::Idle()
{
    currentAnimation = AnimationIndex::AnimationIdle;
    return true;
}
/*
void Character::ProcessCollision(ICollidable* object)
{
    sf::FloatRect charBounds = GetBoundingBox();
    EntityType collidingType = object->GetEntityType();
    // if tile use only lower half of bounds for collision
    if (collidingType == EntityType::tile) {
        charBounds.height *= 1.0f / 2;
        charBounds.top += charBounds.height;
        if (object->GetBoundingBox().intersects(charBounds)) {
            pos_ = oldPos_; // reset position to previous logged position
        }
    } else if (collidingType == EntityType::projectile) {
        // change to better collision
        if (object->GetBoundingBox().intersects(charBounds)) {
        }
    }
}

ICollidable::EntityType Character::GetEntityType() { return ICollidable::EntityType::character; }

void Character::GetHitBy(Projectile* projectile)
{
    if (projectile->GetType() == Projectile::PlayerProjectile) { // change this implementation in projectile
        return;
    }
    TakeDamage(projectile->GetDamage());
}
*/