#pragma once

#ifndef _Projectile_CLASS_
#define _Projectile_CLASS_

#include "Actors/character.hpp"
#include "entity.hpp"

class Character;

class Projectile : public Entity {
public:
    enum Type { PlayerProjectile,
        EnemyProjectile };

public:
    Projectile(sf::Sprite& sprite, sf::Vector2f startPos, bool penetratesObjects = false);

    bool hasHit(Character* c);
    void hit(Character* c);
    int GetDamage() { return damage_; }
    Projectile::Type GetType() { return type_; }
    sf::Vector2f GetDirection() { return direction_; }
    sf::Vector2f GetStartPosition() { return startPos_; }
    float GetTimeExisted() { return timeExisted_; }
    float GetTimeLifeSpan() { return timeLifeSpan_; }
    float GetProjectileSpeed() { return projectileSpeed_; }
    float GetDistanceLifeSpan() { return distanceLifeSpanSquared_; }
    bool Penetrates() { return penetrates_; }
    bool IsAlive() { return alive_; }

    void SetType(Projectile::Type type);
    void SetDirection(sf::Vector2f direction);
    void SetDamage(int damage);
    void SetProjectileSpeed(float projectileSpeed);
    void SetTimeLifeSpan(float timeLifeSpan);
    void SetDistanceLifeSpan(float distanceLifeSpan);
    void SetSprite(sf::Sprite sprite) { sprite_ = sprite; }
    void Kill() { alive_ = false; };

    void Update(float dt);

private:
    Type type_;
    sf::Vector2f direction_;
    sf::Vector2f startPos_;
    std::set<Character*> charactersHit;
    int damage_;
    float projectileSpeed_;

    bool alive_;
    bool penetrates_;
    float distanceLifeSpanSquared_;
    float timeExisted_;
    float timeLifeSpan_;

    void initVariables();
    bool move(float dt, float x, float y);
};
#endif
