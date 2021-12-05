#pragma once

#ifndef _MONSTER_CLASS_
#define _MONSTER_CLASS_

#include "character.hpp"
#include "player.hpp"

class Monster : public Character {
public:
    ~Monster();

    Player& GetPlayer() const;
    virtual std::list<Projectile*> Attack() = 0;
    virtual void Update(float);
    virtual bool Move(float dt) = 0;
    virtual void Render(sf::RenderTarget* target);
    void initVariables();

    float RandomFloatBetween(float min, float max); //
    int RandomIntBetween(int min, int max); //Inclusive min and max

protected:
    Monster(Player* player, sf::Vector2f pos, const std::string& spriteFile);
    Monster(Player* player, float xPos, float yPos, const std::string& spriteFile);
    Player* player_;
    bool movedLastTick;
    sf::RectangleShape healthbar_;
    float staticDamage = 5.0f;
    float getDistanceToPlayer();

    void clampPosToRoom();
};

#endif