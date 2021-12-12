#include "Actors/character.hpp"
#include "Utility/SpriteHelper.hpp"
#define C_X 8
#define C_PIXELS_X 44
#define C_PIXELS_delta 20
#define C_PIXELS_Y 64
#define C_SCALE 2
namespace {
const std::string PLAYER_DEATH_SPRITE = "content/sprites/characters/deathanimation.png";
}
Character::Character(const std::string& filename, sf::Vector2f pos, bool animated)
    : Entity(filename, pos, sf::Vector2f(C_SCALE, C_SCALE))
    , hasAnimation_(animated)
{
    startPos = pos;
    initVariables();

    if (hasAnimation_) {
        sprite_.setTextureRect({ 0, 0, C_PIXELS_X, C_PIXELS_Y });
        animationHandler_ = AnimationHandler(1, 0, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename, PLAYER_DEATH_SPRITE);
    }
}

Character::~Character() { }

void Character::initVariables()
{
    weapon_ = nullptr;

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
    hitpoints_ = std::max(0, hitpoints_ - value);
}

void Character::Heal(int value)
{
    hitpoints_ += value;
    hitpoints_ = std::min(currentMaxHitpoints_, hitpoints_);
}

int Character::GetHitPoints() const
{
    return hitpoints_;
}

void Character::Equip(Weapon* weapon)
{
    weapon_ = weapon;
    attackCooldownLength_ = weapon->GetAttackCooldown();
}

bool Character::IsAlive() { return (hitpoints_ > 0); }

bool Character::Idle()
{
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationIdle);
    return true;
}

bool Character::Dead()
{
    if (hasAnimation_)
        animationHandler_.setAnimation(AnimationIndex::AnimationDeath);
    return true;
}

bool Character::HasWeapon()
{
    return weapon_ != nullptr;
}

std::list<ProjectileUP> Character::emptyList()
{
    std::list<ProjectileUP> emptyList;
    return emptyList;
}
std::list<ProjectileUP> Character::shotProjectileList(sf::Vector2f aimPos)
{
    std::list<ProjectileUP> projectileList;
    auto spriteCenter = GetSpriteCenter();
    auto direction = aimPos - spriteCenter;

    projectileList.push_back(weapon_->Use(direction, spriteCenter));

    for (auto& p : projectileList) {
        p->SetType(characterProjectileType_);
    }

    return projectileList;
}

void Character::generalUpdate(float dt)
{
    currentMaxHitpoints_ = defaultMaxHitpoints_ * LevelUpSystem::GetHPModifier(this);
    oldPos_ = pos_;
    SetPos(pos_);
    updateAttackCooldown(dt);
}

void Character::SetNormalSpeed(float value)
{
    defaultSpeed_ = value;
    currentSpeed_ = defaultSpeed_;
}

void Character::ResetCharacterToBeAlive()
{
    hitpoints_ = currentMaxHitpoints_;
    SetPosAndOldPos({ 200, 200 });
}

int Character::GetMaxHP()
{
    return currentMaxHitpoints_;
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
