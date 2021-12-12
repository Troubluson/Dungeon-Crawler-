#pragma once

#ifndef _BOSS_MONSTER_CLASS_
#define _BOSS_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "monster.hpp"

/**
 * @brief This is the boss monster. It is the most powerful monster and once the player kills it the game is won.
 *
 */
class BossMonster : public Monster {
public:
    BossMonster(PlayerPS player, float xPos, float yPos);
    BossMonster(PlayerPS player, sf::Vector2f pos);
    ~BossMonster();

    virtual std::list<ProjectileUP> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    int currentDir_;

    int attackStyle_ = 0;
    int nofattackStyles_ = 3;

    float angle_ = 0;
    int nofBulletsInCircle_ = 10;
    int nofBulletsToShootTowardsPlayer_ = 5;
    int nofBulletsShot_ = 0;

    sf::Clock attackLoopClock_;
    float spritalAttackCooldownLength_ = 0.1f;
    float normalAttackCooldownLength_ = 0.5f;

    float durationUntilTurn_ = 0.5f;
    float elapsedTurnTime_ = 0.0f;

    void iterateAngle();
    void iterateAttackStyle();
};

#endif