#include "animation.hpp"


Animation::Animation(int x , int y , int width , int height , const std::string& textureName) {

	texture_.loadFromFile(textureName);
	for (int i = 0; i < nFrames_; i++) {
		frames_[i] =  { x + i * width, y, width, height};
	}
}

void Animation::AnimationToSprite(sf::Sprite& sprite) const
{
	sprite.setTexture(texture_);
	sprite.setTextureRect(frames_[iFrame_]);
}

void Animation::Update(float dt)
{

	time_ = time_ +  dt;
	while(time_ >= holdTime_) {
		time_ -= holdTime_;
		NextFrame();
	}
}

void Animation::NextFrame()
{
	if (++iFrame_ >= nFrames_) {
		iFrame_ = 0;
	}
}






