#include "player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/sprites/characters/spritesheet.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, {0.0f, 0.0f})
    , hitpoints_(100)
{
}

int Player::GetHitPoints() const { return hitpoints_; }
