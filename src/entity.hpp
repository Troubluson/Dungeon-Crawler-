#pragma once

#ifndef _ENTITY_CLASS_
#define _ENTITY_CLASS_
class Entity {
 public:
  bool MoveLeft(float dt);
  bool MoveRight(float dt);
  bool MoveDown(float dt);
  bool MoveUp(float dt);

  void Render(sf::RenderTarget* target);

 protected:
  sf::Sprite sprite_;
  sf::Texture texture_;
  float speed = 200;
};
#endif