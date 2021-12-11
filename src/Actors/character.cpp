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

    attackCooldownLength_ = 1.66f;
    attackCooldownLeft = 0.0f;
    CanAttack = true;

    defaultMaxHitpoints_ = 50;
    currentMaxHitpoints_ = defaultMaxHitpoints_ * LevelUpSystem::GetHPModifier(this);
    hitpoints_ = currentMaxHitpoints_;

    currentSpeed_ = defaultSpeed_;
    attackCooldownLength_ = 1.0f;
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
    attackCooldownLeft = attackCooldownLength_;
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

void Character::Equip(Weapon* weapon)
{
    weapon_ = weapon;
    attackCooldownLength_ = weapon->GetAttackCooldown();
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

sf::FloatRect Character::GetBaseBoxAt(sf::Vector2f pos)
{
    auto spriteBounds = sprite_.getGlobalBounds();
    // set to use new position
    spriteBounds.left = pos.x;
    spriteBounds.top = pos.y;
    // use only lower half
    spriteBounds.height *= 1.0f / 2;
    spriteBounds.top += spriteBounds.height;
    return spriteBounds;
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
        it->SetType(characterProjectileType_);
    }

    return projectileList;
}

void Character::generalUpdate(float dt)
{
    currentMaxHitpoints_ = defaultMaxHitpoints_ * LevelUpSystem::GetHPModifier(this);
    oldPos_ = pos_;
    sprite_.setPosition(pos_);
    if (hitpoints_ <= 0) {
        alive_ = false;
    }
    updateAttackCooldown(dt);
}

void Character::SetNormalSpeed(float value)
{
    defaultSpeed_ = value;
    currentSpeed_ = defaultSpeed_;
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
