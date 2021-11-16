#include "game.hpp"

Game::Game() {
  initVariables();
  initWindow();
}

Game::~Game() { delete this->window_; }

void Game::UpdateGame() {
  this->Events();

  UpdateDt();

  // Check collisions
  CheckCollisions();

  // Update projectiles
  for (auto it : projectileVector) {
    it->Update(dt);
  }

  player.Update(dt);
}
// render game frames
void Game::RenderGame() {
  window_->clear();
  player.Render(window_);
  for (auto it : projectileVector) {
    it->Render(window_);
  }
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
      case sf::Event::KeyPressed:
        if (event_.key.code == sf::Keyboard::Space) {
          Projectile *p = new Projectile(50, 50);
          projectileVector.push_back(p);
        }
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

void Game::CheckCollisions() {
  if (projectileVector.size() > 0) {
    std::vector<int> listToDelete;
    int i = 0;
    for (auto projectile : projectileVector) {
      if (projectile->GetSprite().getGlobalBounds().intersects(
              player.GetSprite().getGlobalBounds())) {
        std::cout << "Crash" << std::endl;
        listToDelete.push_back(i);
      }
      i += 1;
    }
    for (auto it : listToDelete) {
      projectileVector.erase(projectileVector.begin() + it);
    }
  }
}