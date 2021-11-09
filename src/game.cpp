#include "game.hpp"

Game::Game() {
  initVariables();
  initWindow();
}

Game::~Game() { delete this->window_; }

void Game::UpdateGame() {
  this->Events();

  UpdateDt();

  /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    Projectile *p = new Projectile(50, 50);
    p->initSprite();
    projectileVector.push_back(p);
  } */

  /* for (auto it : projectileVector) {
    it->Update(dt);
  } */

  player.Update(dt);
  projectile.Update(dt);
}
// render game frames
void Game::RenderGame() {
  window_->clear();
  player.Render(window_);
  projectile.Render(window_);
  window_->display();
  /* for (auto it : projectileVector) {
    it->Render(window_);
  } */
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