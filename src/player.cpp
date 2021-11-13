#include "player.hpp"

Player::Player() : hitpoints_(100) {}

int Player::GetHitPoints() const
{
	return hitpoints_;
}