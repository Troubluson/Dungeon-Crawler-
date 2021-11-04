#include "player.hpp"

Player::Player()
{
  this->initVariables();
  this->initSprite();
}

Player::~Player() {}

void Player::Update() { this->sprite_.setPosition(xPos, yPos); }

void Player::Render(sf::RenderTarget *target) { target->draw(this->sprite_); }

void Player::initVariables() {}

void Player::initSprite()
{
  if (this->texture_.loadFromFile("content/squidman.png"))
  {
    this->sprite_.setTexture(texture_);
    this->sprite_.setScale(sf::Vector2f(3, 3));
    this->sprite_.setPosition(100, 25);
  }
}

bool Player::MoveLeft()
{
  xPos -= speed;
  return true;
}

bool Player::MoveRight()
{
  xPos += speed;
  return true;
}

bool Player::MoveDown()
{
  yPos += speed;
  return true;
}

bool Player::MoveUp()
{
  yPos -= speed;
  return true;
}