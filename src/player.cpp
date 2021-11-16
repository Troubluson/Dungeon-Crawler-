#include "player.hpp"

Player::Player()
{
  initVariables();
  initSprite();
}

Player::~Player() {}

void Player::Update() { sprite_.setPosition(xPos, yPos); }

void Player::Render(sf::RenderTarget *target) { target->draw(sprite_); }

void Player::initVariables() {}

void Player::initSprite()
{
  if (texture_.loadFromFile("content/sprites/squidman.png"))
  {
    sprite_.setTexture(texture_);
    sprite_.setScale(sf::Vector2f(3, 3));
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