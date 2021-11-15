#include "character.hpp"

Character::Character(const std::string &filename, float xPos, float yPos)
{
	xPos_ = xPos;
	yPos_ = yPos;
	initSprite(filename);
}

Character::~Character() {}

void Character::Update()
{
	sprite_.setPosition(xPos_, yPos_);
}

sf::Vector2f Character::GetPosition()
{
	return sprite_.getPosition();
}

void Character::Render(sf::RenderTarget *target)
{
	target->draw(sprite_);
}

void Character::initSprite(const std::string &filename)
{
	if (texture_.loadFromFile(filename))
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