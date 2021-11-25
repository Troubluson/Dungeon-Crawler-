#include "gamebar.hpp"

namespace {
const float HEIGHT = 100;
const float WIDTH = 1280;
}

Gamebar::Gamebar(Player& player)
    : player_(player)
    , hitpoints_(player.GetHitPoints())
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

    if (!font_.loadFromFile("content/fonts/arial.ttf")) {
        std::cout << "load failed" << std::endl;
    }

    sf::Text hp;
    hp.setFont(font_);
    hp.setString(std::to_string(hitpoints_));
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
    //target->draw(hp_);
}

void Gamebar::Update()
{
    int hp = player_.GetHitPoints();
    int newWidth = std::min(100, std::max(0, 2 * (hitpoints_ + hp)));
    greenBar_.setSize(sf::Vector2f(newWidth, 30));
}
