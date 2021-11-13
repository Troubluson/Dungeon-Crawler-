#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "character.hpp"

class Player : public Character
{
public:
  Player();

  int GetHitPoints() const;

private:
  int hitpoints_;
};

#endif