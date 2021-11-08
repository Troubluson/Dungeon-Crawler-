#pragma once

#ifndef _GAME_CLASS_
#define _GAME_CLASS_

#include "player.hpp"

class Game
{
public:
  Game();
  ~Game();

  void UpdateGame();

  void RenderGame();

  bool Running() const;

  void Events();

private:
  sf::VideoMode videomode_;
  sf::RenderWindow *window_;
  bool gameEnder_;
  sf::Event event_;
  Player player_;
  void initVariables();
  void initWindow();

  bool paused = false;
  void manageInput();
};

#endif