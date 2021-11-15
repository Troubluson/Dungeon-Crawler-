#pragma once

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

class Character
{
public:
	Character(const std::string &filename);

	~Character();

	void Update();

	void Render(sf::RenderTarget *target);

	void initSprite(const std::string &filename);

	bool MoveLeft();
	bool MoveRight();
	bool MoveDown();
	bool MoveUp();

	void initVariables();
	sf::Vector2f GetPosition();

private:
	sf::Sprite sprite_;
	float xPos_ = 0;
	float yPos_ = 0;
	float speed_ = 5;
};

#endif