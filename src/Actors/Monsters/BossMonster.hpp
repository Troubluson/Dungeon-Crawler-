#pragma once

#ifndef _BOSS_MONSTER_CLASS_
#define _BOSS_MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "monster.hpp"

class BossMonster : public Monster {
public:
    BossMonster(Player& player, float xPos, float yPos);
    BossMonster(Player& player, sf::Vector2f pos);
    ~BossMonster();

    virtual std::list<Projectile*> Attack();
    virtual bool Move(float dt);

    void initVariables();

private:
    int currentDir_;
    int attackStyle = 0;
    std::vector<Projectile*> fullAttackVector;
    std::vector<Projectile*> toShootVector;
    float durationUntilTurn_ = 0.5f;
    float elapsedTurnTime_ = 0.0f;
    float angle_ = 0;
    int nofBullets = 10;
};

#endif