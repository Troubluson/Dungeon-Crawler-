#include "game.hpp"

Game::Game() {
  initVariables();
  initWindow();
}

Game::~Game() { delete this->window_; }

void Game::UpdateGame() {
  this->Events();

  manageInput();
  UpdateDt();

  player.Update();
}
// render game frames
void Game::RenderGame() {
  window_->clear();
  player.Render(window_);
  window_->display();
}
// Keeps the game running when window is open
bool Game::Running() const { return window_->isOpen(); }

void Game::Events() {
  while (window_->pollEvent(event_)) {
    switch (event_.type) {
      case sf::Event::Closed:
        window_->close();
        break;
      case sf::Event::LostFocus:
        paused = true;
        break;
      case sf::Event::GainedFocus:
        paused = false;
        break;
      default:
        break;
    }
  }
}

void Game::UpdateDt() { dt = dtClock.restart().asSeconds(); }

void Game::initVariables() { gameEnder_ = false; }
// initalize window
void Game::initWindow() {
  videomode_ = sf::VideoMode(1280, 768);
  window_ = new sf::RenderWindow(videomode_, "Dungeon Crawler");
}

void Game::manageInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    player.MoveLeft(dt);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    player.MoveRight(dt);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    player.MoveUp(dt);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    player.MoveDown(dt);
  }
}