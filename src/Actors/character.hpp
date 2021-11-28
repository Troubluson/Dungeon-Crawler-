#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "Combat/Projectile.hpp"
//#include "Interfaces/ICollidable.hpp"
#include "animation.hpp"
#include "entity.hpp"

class Character : public Entity /*, public ICollidable*/ {
public:
    Character(const std::string& filename, sf::Vector2f pos, bool animated = false);

    virtual ~Character();

    void Update(float dt);

    void initSprite(const std::string& filename);

    void initVariables();

    sf::Vector2f GetSpriteCenter();
    const sf::Vector2f& getOldPosition() const;

    void GetHitBy(Projectile* projectile);
    void TakeDamage(int value);

    bool IsAlive();

    bool Idle();
    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);
    // for Entity
    virtual void Move(float) {};
    virtual void Attack(sf::Vector2f, std::list<Projectile*>) {};
    /*
    // for ICollidable
    virtual sf::FloatRect GetBoundingBox() { return sprite_.getGlobalBounds(); }
    virtual void ProcessCollision(ICollidable* object);
    virtual ICollidable::EntityType GetEntityType();
    */

protected:
    /*void GetHitBy(Projectile& projectile);*/
    float clamp(float value, float low, float high);

    int hitpoints_;
    bool alive_;
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
