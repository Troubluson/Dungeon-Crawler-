#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "Combat/Projectile.hpp"
#include "animation.hpp"
#include "entity.hpp"

class Character : public Entity {
public:
    Character(const std::string& filename, sf::Vector2f pos, bool animated = false);

    virtual ~Character();

    void Update(float dt);

    void initSprite(const std::string& filename);

    void initVariables();

    bool Idle();
    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);
    virtual void Move(float) {};
    virtual void Attack(sf::Vector2f, std::list<Projectile*>) {};
    sf::Vector2f GetSpriteCenter();
    const sf::Vector2f& getOldPosition() const;

    void TakeDamage(int value);

    bool IsAlive();

protected:
    int hitpoints_;
    bool alive_;
    float clamp(float value, float low, float high);
    bool hasAnimation_;
    sf::Vector2f velocity_ = { 0.0f, 0.0f };
    static constexpr float speed_ = 400.0f;
    sf::Vector2f oldPos_;

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
