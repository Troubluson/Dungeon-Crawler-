#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "Combat/Projectile.hpp"
//#include "Interfaces/ICollidable.hpp"
#include "animation.hpp"
#include "entity.hpp"

class Projectile;
class Character : public Entity /*, public ICollidable*/ {
public:
    Character(const std::string& filename, sf::Vector2f pos, bool animated = false);

    virtual ~Character();

    virtual void Update(float dt) = 0;
    void UpdateCooldowns(float dt);

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

    bool Idle();
    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);
    // For subclasses, should be = 0
    virtual bool Move(float) { return false; }
    void RevertMove();
    virtual void Attack(sf::Vector2f, std::list<Projectile*>) {};
    void SetOldPos(sf::Vector2f v);
    /*
    // for ICollidable
    virtual sf::FloatRect GetBoundingBox() { return sprite_.getGlobalBounds(); }
    virtual void ProcessCollision(ICollidable* object);
    virtual ICollidable::EntityType GetEntityType();
    */

protected:
    /*void GetHitBy(Projectile& projectile);*/

    int hitpoints_;
    bool alive_;
    bool hasAnimation_;
    sf::Vector2f velocity_ = { 0.0f, 0.0f };
    float currentSpeed_ = 200.0f;

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
