#pragma once

#ifndef _ANIMATION_
#define _ANIMATION_
/// Animation build the characters animation frames from spritesheet and displays them to achive an animated sprite.
class Animation {
public:
    Animation() = default;
    /**
     * @brief Construct a new Animation object
     *
     * @param    x                    x-coordinate of rectangle defining the sprite in spritesheet
     * @param    y                    y-coordinate of rectangle defining the sprite in spritesheet
     * @param    width                width of the character in animation
     * @param    height               height of the character in animation
     * @param    textureName          the spritesheet animation pulls from to create the animation
     */
    Animation(int x, int y, int width, int height, int spacing, const std::string& textureName);
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