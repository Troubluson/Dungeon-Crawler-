#pragma once
#ifndef _ANIMATIONHANDLER_CLASS_
#define _ANIMATIONHANDLER_CLASS_
#include "animation.hpp"

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
private:
    Animation* animations_[static_cast<uint>(AnimationIndex::Count)];
    AnimationIndex currentAnimationIndex_ = AnimationIndex::AnimationDown;

public:
    AnimationHandler() = default;
    AnimationHandler(uint xOffset, uint yOffset, uint width, uint height, uint xSpacing, const std::string& textureLocation, const std::string& deathTexture);
    void setAnimation(AnimationIndex index);
    Animation* getAnimation() const;
};
#endif
