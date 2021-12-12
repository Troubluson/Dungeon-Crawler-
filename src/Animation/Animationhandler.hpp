#pragma once
#ifndef _ANIMATIONHANDLER_CLASS_
#define _ANIMATIONHANDLER_CLASS_
#include "animation.hpp"

typedef std::unique_ptr<Animation> AnimationUP;

enum AnimationIndex {
    AnimationUp,
    AnimationDown,
    AnimationLeft,
    AnimationRight,
    AnimationIdle,
    Count
};

class AnimationHandler {

public:
    AnimationHandler()
        : animations_(0) {};
    ~AnimationHandler();
    AnimationHandler(uint xOffset, uint yOffset, uint width, uint height, uint xSpacing, const std::string& textureLocation);
    void setAnimation(AnimationIndex index);
    Animation* getAnimation() const;

private:
    std::vector<Animation*> animations_;
    AnimationIndex currentAnimationIndex_ = AnimationIndex::AnimationDown;
};
#endif
