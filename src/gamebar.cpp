#include "gamebar.hpp"

namespace {
const float HEIGHT = 100;
const float WIDTH = 1280;
}

Gamebar::Gamebar(PlayerPS player)
    : player_(player)
{
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setFillColor(sf::Color::Black);
    background.setPosition(0, 0);
    background_ = background;

    sf::RectangleShape greenBar(sf::Vector2f(100, 30));
    greenBar.setFillColor(sf::Color::Green);
    greenBar.setPosition(50, 5);
    greenBar_ = greenBar;

    redBar_ = greenBar;
    redBar_.setFillColor(sf::Color::Red);

    violetBar_ = greenBar;
    violetBar_.setFillColor(sf::Color::Magenta);
    violetBar_.setPosition(200, 5);
    violetBar_.setSize(sf::Vector2f(100 - 100 * (player_->GetAttackCooldownLeft() / player_->GetAttackCooldownLength()), 30));

    yellowBar_ = greenBar;
    yellowBar_.setFillColor(sf::Color::Yellow);
    yellowBar_.setPosition(350, 5);
    yellowBar_.setSize(sf::Vector2f(100 - player_->GetDashCooldownLeft() * 50, 30));

    if (!font_.loadFromFile("content/fonts/arial.ttf")) {
        std::cout << "load failed" << std::endl;
    }
}

void Gamebar::Render(sf::RenderTarget* target)
{
    // target->draw(background_);
    target->draw(redBar_);
    target->draw(greenBar_);
    target->draw(violetBar_);
    target->draw(yellowBar_);

    sf::Text hp;
    hp.setFont(font_);
    hp.setString(std::to_string(player_->GetHitPoints()));
    hp.setCharacterSize(25);
    auto hpPositionX = greenBar_.getPosition().x + greenBar_.getSize().x + 5;
    hp.setPosition(hpPositionX, greenBar_.getPosition().y);
    hp.setFillColor(sf::Color::White);
    target->draw(hp);
}

void Gamebar::Update()
{
    int newGreenWidth = std::max(0, std::min(100, 100 * player_->GetHitPoints() / player_->GetMaxHP()));
    greenBar_.setSize(sf::Vector2f(newGreenWidth, 30));

    int newVioletWidth = 100 - 100 * (player_->GetAttackCooldownLeft() / player_->GetAttackCooldownLength());
    violetBar_.setSize(sf::Vector2f(newVioletWidth, 30));

    int newYellowWidth = 100 - 100 * (player_->GetDashCooldownLeft() / player_->GetDashCooldownLength());
    yellowBar_.setSize(sf::Vector2f(newYellowWidth, 30));
}
