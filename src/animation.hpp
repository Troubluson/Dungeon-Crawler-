#pragma once

#ifndef _ANIMATION_
#define _ANIMATION_



class Animation {
public:
	Animation() = default;
	Animation(int ,int ,int ,int ,const std::string& );
	~Animation() {}
	void AnimationToSprite( sf::Sprite& ) const;
	void Update(float dt);

private:
	static constexpr int nFrames_ = 5;
	static constexpr float holdTime_ = 0.1f;
	sf::Texture texture_;
	sf::IntRect frames_[nFrames_];
	int iFrame_ = 0;
	float time_ = 0.0f;
	void NextFrame();


};

#endif