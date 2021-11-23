#pragma once

#ifndef _ANIMATION_
#define _ANIMATION_

class Animation {
public:
    Animation() = default;
    Animation(int x, int y , int width, int height, const std::string& textureName);
    ~Animation() { }
    void AnimationToSprite(sf::Sprite& sprite) const;
    void Update(float dt);

private:
    static constexpr int nFrames_ = 5;
    static constexpr float holdTime_ = 0.15f;
    sf::Texture texture_;
    sf::IntRect frames_[nFrames_];
    int iFrame_ = 0;
    float time_ = 0.0f;
    void NextFrame();
};

#endif