#include "player.hpp"

Player::Player() {
  this->initVariables();
  this->initShape();
}

Player::~Player() {}

void Player::Update() { this->shape_.setPosition(xPos, yPos); }

void Player::Render(sf::RenderTarget *target) { target->draw(this->shape_); }

void Player::initVariables() {}

void Player::initShape() {
  this->shape_.setFillColor(sf::Color::Green);
  this->shape_.setSize(sf::Vector2f(40.f, 40.f));
}

bool Player::MoveLeft() {
  xPos -= speed;
  return true;
}

bool Player::MoveRight() {
  xPos += speed;
  return true;
}

bool Player::MoveDown() {
  yPos += speed;
  return true;
}

bool Player::MoveUp() {
  yPos -= speed;
  return true;
}