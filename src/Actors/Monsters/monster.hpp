#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "Actors/character.hpp"
#include "Actors/player.hpp"

class Monster : public Character {
public:
    ~Monster();

    Player& GetPlayer() const;
    virtual std::list<Projectile*> Attack() = 0;
    virtual void Update(float);
    virtual bool Move(float dt) = 0;
    virtual void Render(sf::RenderTarget* target);
    void initVariables();
    void SetTarget(playerSP target);

protected:
    Monster(playerSP player, sf::Vector2f pos, const std::string& spriteFile);
    Monster(playerSP player, float xPos, float yPos, const std::string& spriteFile);
    std::shared_ptr<Player> player_;
    sf::RectangleShape healthbar_;
    float staticDamage = 5.0f;
    float getDistanceToPlayer();
};

#endif
