#include "player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/spritesheet.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, {640.0f, 320.0f})
    , hitpoints_(100)
{
}

int Player::GetHitPoints() const { return hitpoints_; }
