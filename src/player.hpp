#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "entity.hpp"

class Player : public Entity {
 public:
  Player();
  virtual ~Player();

  void Update(float dt);

 private:
  void initVariables();

  void initSprite();
};

#endif