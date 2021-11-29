#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "Combat/Projectile.hpp"
#include "animation.hpp"
#include "entity.hpp"

class Projectile;

class Character : public Entity {
public:
    Character(const std::string& filename, sf::Vector2f pos, bool animated = false);

    virtual ~Character();

    virtual void Update(float dt) = 0;
    void UpdateCooldowns(float dt);

    void initSprite(const std::string& filename);

    void initVariables();

    bool Idle();
    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);
    void Dash();
    virtual void Move(float) {};
    virtual void Attack(sf::Vector2f, std::list<Projectile*>) {};
    sf::Vector2f GetSpriteCenter();

    void TakeDamage(int value);
    void ResetAttackCooldown();
    void ResetDashCooldown();
    bool CanAttack;
    bool CanDash;
    bool IsDashing;

    bool IsAlive();

protected:
    int hitpoints_;
    bool alive_;
    float clamp(float value, float low, float high);
    bool hasAnimation_;
    sf::Vector2f velocity_ = { 0.0f, 0.0f };
    float normalSpeed_;
    float dashSpeed;
    float dashDurationLength;
    float dashDurationLeft;
    float currentSpeed_;
    sf::Vector2f oldPos_;

    float attackCooldownLength;
    float attackCooldownLeft;
    void updateAttackCooldown(float dt);
    float dashCooldownLength;
    float dashCooldownLeft;
    void updateDashCooldown(float dt);

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
