#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "entity.hpp"

class Character : public Entity {
public:
    Character(const std::string& filename, float xPos, float yPos);

    virtual ~Character();

    void Update();

    void initSprite(const std::string& filename);

    void initVariables();

    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);
    virtual void Move(float) {

    };

    void TakeDamage(int value);

    bool GetAlive();

private:
    float speed_ = 200;
    int hitpoints_;
    bool alive_;
    float clamp(float value, float low, float high);
};

#endif