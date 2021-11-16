#include "player.hpp"

Player::Player() {
  initVariables();
  initSprite();
}

Player::~Player() {}

void Player::Update(float dt) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    MoveLeft(dt);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    MoveRight(dt);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    MoveUp(dt);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    MoveDown(dt);
  }
}

void Player::initVariables() {}

void Player::initSprite() {
  if (texture_.loadFromFile("content/squidman.png")) {
    sprite_.setTexture(texture_);
    sprite_.setScale(sf::Vector2f(3, 3));
  }
}