#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "entity.hpp"

class Character : public Entity {
public:
    Character(const std::string& filename, float xPos, float yPos);

    ~Character();

    void Update();

    void initSprite(const std::string& filename);

    void initVariables();
    sf::Vector2f GetPosition();

    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);

private:
    float speed_ = 200;
};

#endif