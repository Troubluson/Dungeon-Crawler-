#pragma once
#ifndef _ANIMATIONHANDLER_CLASS_
#define _ANIMATIONHANDLER_CLASS_
#include "animation.hpp"

typedef std::shared_ptr<Animation> AnimationPS;

enum AnimationIndex {
    AnimationUp,
    AnimationDown,
    AnimationLeft,
    AnimationRight,
    AnimationIdle,
    AnimationDeath,
    Count
};

class AnimationHandler {

public:
    AnimationHandler()
        : animations_(0) {};
    ~AnimationHandler();
    AnimationHandler(uint xOffset, uint yOffset, uint width, uint height, uint xSpacing, const std::string& textureLocation, const std::string& deathTexture);
    void setAnimation(AnimationIndex index);
    Animation* getAnimation() const;

private:
    std::vector<AnimationPS> animations_;
    AnimationIndex currentAnimationIndex_ = AnimationIndex::AnimationDown;
};
#endif
