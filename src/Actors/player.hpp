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

    float GetDashCooldownLeft() const { return dashCooldownLeft_; };
    float GetDashCooldownLength() const { return dashCooldownLength_; };

    bool CanDash;
    bool IsDashing;

private:
    float dashSpeed_;
    float dashDurationLength_;
    float dashDurationLeft_;
    bool deadAnimationPlayed = false;
    float dt_time = 0;
    float dashCooldownLength_;
    float dashCooldownLeft_;
    void updateDashCooldown(float dt);
};

#endif