#include "player.hpp"

Player::Player() : Character("content/squidman.png", 0, 0), hitpoints_(100) {}

int Player::GetHitPoints() const
{
	return hitpoints_;
}
