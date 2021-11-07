#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

class Character
{
public:
	Character();

	~Character();

	void Update();

	void Render(sf::RenderTarget *target);

	void initSprite();

	bool MoveLeft();
	bool MoveRight();
	bool MoveDown();
	bool MoveUp();

	void initVariables();

private:
	sf::Sprite sprite_;
	sf::Texture texture_;

	float xPos_ = 0;
	float yPos_ = 0;
	float speed_ = 5;
};

#endif