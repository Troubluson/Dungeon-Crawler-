#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "Actors/character.hpp"
#include "Combat/Health/Potion.hpp"

class Player : public Character {
public:
    Player();
    ~Player() {};
    int GetHitPoints() const;

    virtual void Update(float dt);

    void Dash();
    std::list<Projectile*> Attack(sf::Vector2f aimPos);

    void initVariables();

    void ResetDashCooldown();

    float GetDashCooldownLeft() const { return dashCooldownLeft; };
    float GetDashCooldownLength() const { return dashCooldownLength; };

    bool CanDash;
    bool IsDashing;

    void AddPotion(Potion* potion);
    void UsePotion(const std::string& colour);

private:
    float dashSpeed;
    float dashDurationLength;
    float dashDurationLeft;

    float dashCooldownLength;
    float dashCooldownLeft;
    void updateDashCooldown(float dt);

    std::vector<Potion*> inventory_;
};

#endif