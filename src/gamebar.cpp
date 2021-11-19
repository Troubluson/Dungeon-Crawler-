#include "gamebar.hpp"

namespace {
const float WIDTH = 768;
const float HEIGHT = 100;
}

Gamebar::Gamebar(Player player)
    : player_(player)
{
    sf::RectangleShape background(sf::Vector2f(HEIGHT, WIDTH));
    background.setFillColor(sf::Color::Black);
    background.setPosition(1180, 0);
    background_ = background;

    sf::RectangleShape playerBar(sf::Vector2f(30, 2 * player.GetHitpoints()));
    playerBar.setFillColor(sf::Color::Green);
    playerBar.setPosition(1200, 30);
    playerBar_ = playerBar;
}

void Gamebar::Render(sf::RenderTarget* target)
{
    target->draw(background_);
    target->draw(playerBar_);
}

void Gamebar::Update()
{
}