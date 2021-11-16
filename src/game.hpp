#pragma once

#ifndef _GAME_CLASS_
#define _GAME_CLASS_

#include <vector>

#include "Combat/Projectile.hpp"
#include "player.hpp"

class Game {
 public:
  Game();
  ~Game();

  void UpdateGame();

  void RenderGame();

  bool Running() const;

  void Events();

  void UpdateDt();

 private:
  sf::VideoMode videomode_;
  sf::RenderWindow *window_;
  bool gameEnder_;
  sf::Event event_;
  Player player;
  void initVariables();
  void initWindow();

  sf::Clock dtClock;
  float dt;

  bool paused = false;
  std::vector<Projectile *> projectileVector;

  void CheckCollisions();
};

#endif