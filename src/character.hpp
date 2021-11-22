#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "animation.hpp"



class Character {
private:
    enum class AnimationIndex {
        AnimationUp,
        AnimationDown,
        AnimationLeft,
        AnimationRight,
        AnimationIdle,
        Count
    };
public:
    Character(const std::string& filename, const sf::Vector2f& pos_);

    ~Character();

    void Update();

    void Render(sf::RenderTarget* target);

    void initSprite(const std::string& filename);

    bool Idle();
    bool MoveLeft();
    bool MoveRight();
    bool MoveDown();
    bool MoveUp();

    void initVariables();
    sf::Vector2f GetPosition();

private:
    sf::Vector2f oldPos_;
    sf::Sprite sprite_;
    sf::Texture texture_;
    bool player_char_;
    sf::Vector2f pos_;
    sf::Vector2f velocity_ = {0.0f, 0.0f};
    static constexpr float speed_ = 5.0f;
    float dt_ = 0;
    Animation* Animations[int(AnimationIndex::Count)];
    AnimationIndex currentAnimation = AnimationIndex::AnimationDown;

};

#endif
