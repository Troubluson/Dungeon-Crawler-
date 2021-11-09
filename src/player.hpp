#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

class Player {
 public:
  Player();
  virtual ~Player();

  void Update();

  void Render(sf::RenderTarget* target);

  bool MoveLeft(float dt);
  bool MoveRight(float dt);
  bool MoveDown(float dt);
  bool MoveUp(float dt);

 private:
  sf::Sprite sprite_;
  sf::Texture texture_;
  void initVariables();

  void initSprite();

  float xPos = 0;
  float yPos = 0;
  float speed = 200;
};

#endif