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
        Animations[int(AnimationIndex::AnimationIdle)] = new Animation(1, 0, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename);
        Animations[int(AnimationIndex::AnimationLeft)] = new Animation(1, C_PIXELS_Y, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename);
        Animations[int(AnimationIndex::AnimationRight)] = new Animation(1, C_PIXELS_Y * 2, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename);
        Animations[int(AnimationIndex::AnimationUp)] = new Animation(1, C_PIXELS_Y * 3, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename);
        Animations[int(AnimationIndex::AnimationDown)] = new Animation(1, C_PIXELS_Y * 4, C_PIXELS_X, C_PIXELS_Y, C_PIXELS_delta, filename);
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
}

void Character::initVariables()
{
    weapon_ = nullptr;
    alive_ = true;
    hitpoints_ = 50;
    currentSpeed_ = normalSpeed_;
    attackCooldownLength = 1.0f;
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
void Character::DamageAnotherCharacter(Character* target)
{
    target->TakeDamage(staticDamage);
}

std::list<Projectile*> Character::FireWeapon(sf::Vector2f aimPosition)
{
    std::list<Projectile*> list;
    auto spriteCenter = GetSpriteCenter();
    auto direction = aimPosition - spriteCenter;
    auto newProjectile = weapon_->Use(direction, spriteCenter);
    list.push_back(newProjectile);

    for (auto it : list) {
        it->SetType(characterBulletType);
    }

    return list;
}

std::list<Projectile*> Character::Attack(Character* target)
{
    std::list<Projectile*> attackProjectileList;
    if (!CanAttack) {
        return attackProjectileList;
    }

    ResetAttackCooldown();

    if (weapon_ == nullptr) {
        DamageAnotherCharacter(target);
        return attackProjectileList;
    } else {
        attackProjectileList = FireWeapon(target->GetSpriteCenter());
        return attackProjectileList;
    }
}
std::list<Projectile*> Character::Attack(sf::Vector2f aimPosition)
{
    std::list<Projectile*> attackProjectileList;
    if (!CanAttack) {
        return attackProjectileList;
    }

    ResetAttackCooldown();

    if (weapon_ == nullptr) {
        return attackProjectileList;
    } else {
        attackProjectileList = FireWeapon(aimPosition);
        return attackProjectileList;
    }
}

void Character::Equip(Weapon* weapon)
{
    weapon_ = weapon;
    attackCooldownLength = weapon->GetAttackCooldown();
}

bool Character::IsAlive() { return alive_; }

bool Character::Idle()
{
    currentAnimation = AnimationIndex::AnimationIdle;
    return true;
}

bool Character::HasWeapon()
{
    if (weapon_ == nullptr) {
        return false;
    }
    return true;
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
