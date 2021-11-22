#include "gamebar.hpp"

namespace {
const float HEIGHT = 100;
const float WIDTH = 1280;
}

Gamebar::Gamebar(int hitpoints)
    : hitpoints_(hitpoints)
{
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setFillColor(sf::Color::Black);
    background.setPosition(0, 0);
    background_ = background;

    sf::RectangleShape playerBar(sf::Vector2f(2 * hitpoints_, 30));
    playerBar.setFillColor(sf::Color::Green);
    playerBar.setPosition(30, 30);
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