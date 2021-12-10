#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "Actors/character.hpp"

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

private:
    float dashSpeed;
    float dashDurationLength;
    float dashDurationLeft;
    bool deadAnimationPlayed = false;
    float dt_time = 0;
    float dashCooldownLength;
    float dashCooldownLeft;
    void updateDashCooldown(float dt);
};

#endif