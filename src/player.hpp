#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

class Player {
 public:
  Player();
  virtual ~Player();

  void Update();

  void Render(sf::RenderTarget *target);

  bool MoveLeft();
  bool MoveRight();
  bool MoveDown();
  bool MoveUp();

 private:
  sf::RectangleShape shape_;

  void initVariables();

  void initShape();

  float xPos = 0;
  float yPos = 0;
  float speed = 5;
};

#endif