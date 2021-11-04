#include "player.hpp"

Player::Player()
{
  this->initVariables();
  this->initSprite();
}

Player::~Player() {}

void Player::Update() { this->shape_.setPosition(xPos, yPos); }

void Player::Render(sf::RenderTarget *target) { target->draw(this->shape_); }

void Player::initVariables() {}

void Player::initSprite()
{

  if (this->sprite_.loadFromFile("content/squidman.png"))
  {
    this->shape_.setTexture(&sprite_);
    this->shape_.setSize(sf::Vector2f(200.f, 200.f));
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