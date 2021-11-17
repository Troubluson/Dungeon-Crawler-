

#ifndef _ANIMATION_
#define _ANIMATION_



class Animation {
public:
	Animation(int x , int y , int width, int height, const std::string& textureName);
	~Animation() {}
	void AnimationToSprite( sf::Sprite& ) const;
	void Update(float dt);

private:
	static constexpr int nFrames_ = 6;
	static constexpr float holdTime_ = 0.1f;
	sf::Texture texture_;
	sf::IntRect frames_[nFrames_];
	int iFrame_ = 0;
	float time_ = 0.0f;
	void NextFrame();


};

#endif