#include "game.hpp"

Game::Game() : player_(new Player()), monster_(new Monster(200, 200))
{
  initVariables();
  initWindow();
}

Game::~Game()
{
  delete window_;
  delete monster_;
  delete player_;
}

void Game::UpdateGame()
{
  Events();

  manageInput();

  player_->Update();
}
// render game frames
void Game::RenderGame()
{
  window_->clear();
  player_->Render(window_);
  monster_->Render(window_);
  window_->display();
}
// Keeps the game running when window is open
bool Game::Running() const { return window_->isOpen(); }

void Game::Events()
{
  while (window_->pollEvent(event_))
  {
    switch (event_.type)
    {
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

void Game::initVariables()
{
  gameEnder_ = false;
}
// initalize window
void Game::initWindow()
{
  videomode_ = sf::VideoMode(1280, 768);
  window_ = new sf::RenderWindow(videomode_, "Dungeon Crawler");
}

void Game::manageInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    player_->MoveLeft();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    player_->MoveRight();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    player_->MoveUp();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    player_->MoveDown();
  }
}