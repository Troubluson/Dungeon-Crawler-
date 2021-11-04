#include "game.hpp"

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window_;
}

void Game::UpdateGame()
{
	this->Events();
}
// render game frames
void Game::RenderGame()
{
	this->window_->clear();
	this->player.Render(this->window_);
	this->window_->display();
}
// Keeps the game running when window is open
bool Game::Running() const
{
	return this->window_->isOpen();
}

void Game::Events()
{
	while (this->window_->pollEvent(this->event_))
	{
		switch (this->event_.type)
		{
		case sf::Event::Closed:
			this->window_->close();
			break;
		default:
			break;
		}
	}
}

void Game::initVariables()
{
	this->gameEnder_ = false;
}
// initalize window
void Game::initWindow()
{
	this->videomode_ = sf::VideoMode(640, 480);
	this->window_ = new sf::RenderWindow(this->videomode_, "Dungeon Crawler");
}
