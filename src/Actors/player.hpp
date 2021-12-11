#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "Actors/character.hpp"

class Player : public Character {
public:
    Player();
    ~Player() {};

    virtual void Update(float dt);

    void Dash();
    std::list<ProjectileUP> Attack(sf::Vector2f aimPos);

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

    float dashCooldownLength;
    float dashCooldownLeft;
    void updateDashCooldown(float dt);
};
typedef std::shared_ptr<Player> PlayerPS;

#endif