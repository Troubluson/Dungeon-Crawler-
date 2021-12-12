#pragma once

#ifndef _Projectile_CLASS_
#define _Projectile_CLASS_

#include "entity.hpp"

class Character;

class Projectile : public Entity {
public:
    enum Type { PlayerProjectile,
        EnemyProjectile };

public:
    Projectile(sf::Sprite& sprite, sf::Vector2f startPos, bool penetratesObjects = false);

    /**
     * @brief Function to check if this projectile has already hit a specific character.
     *
     * @param c character to check if this projectile has hit
     * @return true if projectile has hit charachter c
     * @return false if projectile has not hit character c
     */
    bool HasHit(Character* c);

    /**
     * @brief Function to add character c to the characters this projectile has hit so it cannot hit it again.
     *
     * @param c character to add
     */
    void Hit(Character* c);

    /**
     * @brief Get the Damage that this projectile will make when colliding.
     *
     * @return int damage of this projectile
     */
    int GetDamage() { return damage_; }

    /**
     * @brief Get the Type of this projectile.
     *
     * @return Projectile::Type the type of this projectile
     */
    Projectile::Type GetType() { return type_; }

    /**
     * @brief Get the Direction that this Projectile is travelling in.
     *
     * @return sf::Vector2f direction of this projectile
     */
    sf::Vector2f GetDirection() { return direction_; }

    /**
     * @brief Get the position that this Projectile was spawned at.
     *
     * @return sf::Vector2f start postion of this Projectile
     */
    sf::Vector2f GetStartPosition() { return startPos_; }

    /**
     * @brief Get the time in seconds that this Projectile has existed.
     *
     * @return float timeExisted of this Projectile in seconds
     */
    float GetTimeExisted() { return timeExisted_; }

    /**
     * @brief Get the time in seconds that this Projectile will exist before being deleted.
     *
     * @return float timeLifeSpan of this Projectile in seconds
     */
    float GetTimeLifeSpan() { return timeLifeSpan_; }

    /**
     * @brief Get the speed that this Projectile is travelling at
     *
     * @return float speed of this Projectile
     */
    float GetProjectileSpeed() { return projectileSpeed_; }

    /**
     * @brief Get the distance that this Projectile will travell before being deleted.
     *
     * @return float distanceLifeSpan of this Projectile
     */
    float GetDistanceLifeSpan() { return distanceLifeSpanSquared_; }

    /**
     * @brief Check if this Projectile can penetrate characters or not. Meaning if it can go through characters.
     *
     * @return true Meaning that this Projectile can penetrate characters
     * @return false Meaning that this Projectile can not penetrate characters
     */
    bool Penetrates() { return penetrates_; }

    /**
     * @brief Checks if this Projectile should be deleted or not
     *
     * @return true Meaning that this Projectile should not be deleted
     * @return false Meaning that this Projectile should be deleted
     */
    bool IsAlive() { return alive_; }

    /**
     * @brief Set the Type of this projectile.
     *
     * @param type the new type of this projectile
     */
    void SetType(Projectile::Type type);

    /**
     * @brief Set the Direction of this projectile.
     *
     * @param direction the new Direction of this projectile
     */
    void SetDirection(sf::Vector2f direction);

    /**
     * @brief Set the Damage of this projectile.
     *
     * @param damage the new Damage of this projectile
     */
    void SetDamage(int damage);

    /**
     * @brief Set the Speed of this projectile.
     *
     * @param projectileSpeed the new Speed of this projectile
     */
    void SetProjectileSpeed(float projectileSpeed);

    /**
     * @brief Set the timeLifeSpan of this projectile.
     *
     * @param timeLifeSpan the new timeLifeSpan of this projectile
     */
    void SetTimeLifeSpan(float timeLifeSpan);

    /**
     * @brief Set the distanceLifeSpan of this projectile.
     *
     * @param distanceLifeSpan the new distanceLifeSpan of this projectile
     */
    void SetDistanceLifeSpan(float distanceLifeSpan);

    /**
     * @brief Set the Sprite of this Projectile
     *
     * @param sprite the new Sprite of this projectile
     */
    void SetSprite(sf::Sprite sprite) { sprite_ = sprite; }

    /**
     * @brief Function to make the game delete this Projectile
     *
     */
    void Kill() { alive_ = false; };

    /**
     * @brief Function to update this projectile
     *
     * @param dt deltatime to compensate framerate
     */
    void Update(float dt);

private:
    Type type_;
    sf::Vector2f direction_;
    sf::Vector2f startPos_;
    std::set<Character*> charactersHit_;
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

typedef std::unique_ptr<Projectile> ProjectileUP;

#endif
