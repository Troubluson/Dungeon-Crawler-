#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "Actors/character.hpp"
#include "Combat/Weapons/Weapon.hpp"

class Weapon;
class Player : public Character {
public:
    Player();
    ~Player() {};
    int GetHitPoints() const;

    virtual void Update(float dt);
    void Attack(sf::Vector2f mousePos, std::list<Projectile*>& worldProjectiles);
    void Equip(Weapon* weapon);
    void Dash();

    void initVariables();

    void ResetAttackCooldown();
    void ResetDashCooldown();

    float AttackCooldownLeft() const;
    float DashCooldownLeft() const;

    bool CanAttack;
    bool CanDash;
    bool IsDashing;

private:
    Weapon* weapon_;

    float normalSpeed_;
    float dashSpeed;
    float dashDurationLength;
    float dashDurationLeft;

    float attackCooldownLength;
    float attackCooldownLeft;
    void updateAttackCooldown(float dt);
    float dashCooldownLength;
    float dashCooldownLeft;
    void updateDashCooldown(float dt);
};

#endif