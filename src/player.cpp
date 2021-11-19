#include "player.hpp"

namespace {
const std::string PLAYER_SPRITE = "content/sprites/squidman.png";
}

Player::Player()
    : Character(PLAYER_SPRITE, 0, 0)
    , gamebar_(Gamebar(*this))
{
}

void Player::Render(sf::RenderTarget* target)
{
    gamebar_.Render(target);
}
