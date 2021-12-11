#include "Actors/character.hpp"
#include "Utility/SpriteHelper.hpp"
#define C_X 8
#define C_PIXELS_X 44
#define C_PIXELS_delta 20
#define C_PIXELS_Y 64
#define C_SCALE 2

Character::Character(const std::string& filename, sf::Vector2f pos, bool animated)
    : Entity(filename, pos, sf::Vector2f(C_SCALE, C_SCALE))
    , hasAnimation_(animated)
{
    initVariables();

    if (hasAnimation_) {
        sprite_.setTextureRect({ 0, 0, C_PIXELS_X, C_PIXELS_Y });
        animationHandler_ = AnimationHandler(1, 0, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename);
    }
}

Character::~Character() { }

void Character::initVariables()
{
    weapon_ = nullptr;
    alive_ = true;

    normalSpeed_ = 200.0f;
    attackCooldownLength = 1.66f;
    attackCooldownLeft = 0.0f;
    CanAttack = true;

    hitpoints_ = 50;
    currentSpeed_ = normalSpeed_;
    attackCooldownLength = 1.0f;
}

bool Character::MoveLeft(float dt)
{
    pos_.x -= currentSpeed_ * dt;
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationLeft);
    return true;
}

bool Character::MoveRight(float dt)
{
    pos_.x += currentSpeed_ * dt;
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationRight);
    return true;
}

bool Character::MoveDown(float dt)
{
    pos_.y += currentSpeed_ * dt;
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationDown);
    return true;
}

bool Character::MoveUp(float dt)
{
    pos_.y -= currentSpeed_ * dt;
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationUp);
    return true;
}

void Character::RevertMove()
{
    pos_ = oldPos_;
}

void Character::ResetAttackCooldown()
{
    attackCooldownLeft = attackCooldownLength;
    CanAttack = false;
}

void Character::updateAttackCooldown(float dt)
{
    attackCooldownLeft = std::max(0.0f, attackCooldownLeft - dt);
    if (attackCooldownLeft <= 0.0f) {
        CanAttack = true;
    }
}

void Character::TakeDamage(int value)
{
    hitpoints_ -= value;
}

int Character::GetHitPoints() const
{
    return hitpoints_;
}

void Character::Equip(Weapon* weapon)
{
    weapon_ = weapon;
    attackCooldownLength = weapon->GetAttackCooldown();
}

bool Character::IsAlive() { return alive_; }

bool Character::Idle()
{
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationIdle);
    return true;
}

bool Character::HasWeapon()
{
    return weapon_ != nullptr;
}

std::list<Projectile*> Character::emptyList()
{
    std::list<Projectile*> emptyList;
    return emptyList;
}
std::list<Projectile*> Character::shotProjectileList(sf::Vector2f aimPos)
{
    std::list<Projectile*> projectileList;
    auto spriteCenter = GetSpriteCenter();
    auto direction = aimPos - spriteCenter;

    Projectile* newProjectile = weapon_->Use(direction, spriteCenter);
    projectileList.push_back(newProjectile);

    for (auto it : projectileList) {
        it->SetType(characterProjectileType);
    }

    return projectileList;
}

void Character::generalUpdate(float dt)
{
    oldPos_ = pos_;
    sprite_.setPosition(pos_);
    if (hitpoints_ <= 0) {
        alive_ = false;
    }
    updateAttackCooldown(dt);
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
