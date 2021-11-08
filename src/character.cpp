#include "character.hpp"

Character::Character()
{
	initSprite();
}

Character::~Character() {}

void Character::Update()
{
	sprite_.setPosition(xPos_, yPos_);
}

void Character::Render(sf::RenderTarget *target)
{
	target->draw(sprite_);
}

void Character::initSprite()
{
	if (texture_.loadFromFile("content/squidman.png"))
	{
		sprite_.setTexture(texture_);
		sprite_.setScale(sf::Vector2f(3, 3));
	}
}

bool Character::MoveLeft()
{
	xPos_ -= speed_;
	return true;
}

bool Character::MoveRight()
{
	xPos_ += speed_;
	return true;
}

bool Character::MoveDown()
{
	yPos_ += speed_;
	return true;
}

bool Character::MoveUp()
{
	yPos_ -= speed_;
	return true;
}