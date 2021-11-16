#include "player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/sprites/squidman.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, 0, 0)
    , hitpoints_(100)
{
}

int Player::GetHitPoints() const { return hitpoints_; }
