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

    sf::RectangleShape greenBar(sf::Vector2f(2 * hitpoints_, 30));
    greenBar.setFillColor(sf::Color::Green);
    greenBar.setPosition(30, 30);
    greenBar_ = greenBar;

    redBar_ = greenBar;
    redBar_.setFillColor(sf::Color::Red);

    sf::Font font;
    if (!font.loadFromFile("content/arial.ttf")) {
    }

    sf::Text hp;
    hp.setFont(font);
    hp.setString("100");
    hp.setCharacterSize(15);
    hp.setPosition(40, 30);
    hp.setFillColor(sf::Color::White);
    hp_ = hp;
}

void Gamebar::Render(sf::RenderTarget* target)
{
    target->draw(background_);
    target->draw(redBar_);
    target->draw(greenBar_);
}

void Gamebar::Update()
{
}