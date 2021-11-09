#include "entity.hpp"

void Entity::Render(sf::RenderTarget* target) { target->draw(sprite_); }

bool Entity::MoveLeft(float dt) {
  sprite_.move(-speed * dt, 0);
  return true;
}

bool Entity::MoveRight(float dt) {
  sprite_.move(speed * dt, 0);
  return true;
}

bool Entity::MoveDown(float dt) {
  sprite_.move(0, speed * dt);
  return true;
}

bool Entity::MoveUp(float dt) {
  sprite_.move(0, -speed * dt);
  return true;
}