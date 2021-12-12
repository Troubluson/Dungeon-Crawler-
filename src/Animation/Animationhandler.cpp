#include "Animationhandler.hpp"

AnimationHandler::AnimationHandler(uint xOffset, uint yOffset, uint width, uint height, uint xSpacing, const std::string& textureLocation, const std::string& deathTexture)
    : animations_(AnimationIndex::Count)
{
    animations_[uint(AnimationIndex::AnimationDeath)] = new Animation(0, 0, 64, 64, 0, deathTexture);
    animations_[uint(AnimationIndex::AnimationIdle)] = new Animation(xOffset, 0, width, height, xSpacing, textureLocation);
    animations_[uint(AnimationIndex::AnimationLeft)] = new Animation(xOffset, yOffset + height, width, height, xSpacing, textureLocation);
    animations_[uint(AnimationIndex::AnimationRight)] = new Animation(xOffset, yOffset + height * 2, width, height, xSpacing, textureLocation);
    animations_[uint(AnimationIndex::AnimationUp)] = new Animation(xOffset, yOffset + height * 3, width, height, xSpacing, textureLocation);
    animations_[uint(AnimationIndex::AnimationDown)] = new Animation(xOffset, yOffset + height * 4, width, height, xSpacing, textureLocation);
}

AnimationHandler::~AnimationHandler()
{
    /*for (auto p : animations_) {
        delete p;
    }*/
}

void AnimationHandler::setAnimation(AnimationIndex index)
{
    currentAnimationIndex_ = index;
}

Animation* AnimationHandler::getAnimation() const
{
    return animations_[currentAnimationIndex_];
}
