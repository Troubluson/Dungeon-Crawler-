#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "Combat/Projectile.hpp"
//#include "Interfaces/ICollidable.hpp"
#include "Combat/Weapons/Weapon.hpp"
#include "animation.hpp"
#include "entity.hpp"

class Character : public Entity /*, public ICollidable*/ {
public:
    Character(const std::string& filename, sf::Vector2f pos, bool animated = false);

    virtual ~Character();

    virtual void Update(float dt) = 0;

    void DamageAnotherCharacter(Character* target);
    std::list<Projectile*> FireProjectiles(sf::Vector2f aimPosition);
    void Equip(Weapon* weapon);

    void initVariables();
    /**
     * @brief Get the lower half of bounding box if the character was at the position given as argument
     *
     * @param    pos                  the wanted position
     * @return sf::FloatRect
     */
    sf::FloatRect GetBaseBoxAt(sf::Vector2f pos);

    void TakeDamage(int value);

    bool IsAlive();
    bool HasWeapon();

    bool Idle();
    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);
    // For subclasses, should be = 0
    virtual bool Move(float)
    {
        return false;
    }
    void RevertMove();

    void ResetAttackCooldown();
    float GetAttackCooldownLeft() const { return attackCooldownLeft; };
    float GetAttackCooldownLength() const { return attackCooldownLength; };
    bool CanAttack;
    /*
    // for ICollidable
    virtual sf::FloatRect GetBoundingBox() { return sprite_.getGlobalBounds(); }
    virtual void ProcessCollision(ICollidable* object);
    virtual ICollidable::EntityType GetEntityType();
    */

protected:
    /*void GetHitBy(Projectile& projectile);*/

    Weapon* weapon_;
    int hitpoints_;
    bool alive_;
    bool hasAnimation_;
    float currentSpeed_;
    float normalSpeed_ = 200.0f;
    float staticDamage = 5.0f;

    float attackCooldownLength;
    float attackCooldownLeft;
    void updateAttackCooldown(float dt);

    enum class AnimationIndex {
        AnimationUp,
        AnimationDown,
        AnimationLeft,
        AnimationRight,
        AnimationIdle,
        Count
    };

    Animation* Animations[int(AnimationIndex::Count)];
    AnimationIndex currentAnimation = AnimationIndex::AnimationDown;
};
#endif
