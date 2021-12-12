#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Combat/Health/HealthPotions.hpp"

class Monster : public Character {
public:
    virtual ~Monster();

    Player& GetPlayer() const;
    virtual std::list<ProjectileUP> Attack() = 0;
    virtual void Update(float);
    virtual bool Move(float dt) = 0;
    virtual void Render(sf::RenderTarget* target);
    void initVariables();
    void SetTarget(PlayerPS target);
    Potion* ReturnPotion();

protected:
    Monster(PlayerPS player, sf::Vector2f pos, const std::string& spriteFile);
    Monster(PlayerPS player, float xPos, float yPos, const std::string& spriteFile);
    std::shared_ptr<Player> player_;
    sf::RectangleShape healthbar_;
    float staticDamage_ = 5.0f;
    float getDistanceToPlayer();
    bool inRangeOfPlayer();
    bool movedLastTick_;

    bool moveTowardsPlayer(float dt);

    void clampPosToRoom();
};

#endif
