#include "player.hpp"

Player::Player() : Character("content/squidman.png"), hitpoints_(100) {}

int Player::GetHitPoints() const
{
	return hitpoints_;
}
