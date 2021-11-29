#include "gamebar.hpp"

namespace {
const float HEIGHT = 100;
const float WIDTH = 1280;
}

Gamebar::Gamebar(Player* player)
    : player_(player)
    , hitpoints_(player->GetHitPoints())
    , attackCooldown_(player->GetAttackCooldownLeft())
    , dashCooldown_(player->GetDashCooldownLeft())
{
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setFillColor(sf::Color::Black);
    background.setPosition(0, 0);
    background_ = background;

    sf::RectangleShape greenBar(sf::Vector2f(2 * hitpoints_, 30));
    greenBar.setFillColor(sf::Color::Green);
    greenBar.setPosition(50, 5);
    greenBar_ = greenBar;

    redBar_ = greenBar;
    redBar_.setFillColor(sf::Color::Red);

    violetBar_ = greenBar;
    violetBar_.setFillColor(sf::Color::Magenta);
    violetBar_.setPosition(200, 5);
    violetBar_.setSize(sf::Vector2f(100 - 100 * (attackCooldown_ / player_->GetAttackCooldownLength()), 30));
    std::cout << "AttackCooldown = " << attackCooldown_ << std::endl;
    std::cout << "AttackCooldownLength = " << player_->GetAttackCooldownLength() << std::endl;

    yellowBar_ = greenBar;
    yellowBar_.setFillColor(sf::Color::Yellow);
    yellowBar_.setPosition(350, 5);
    yellowBar_.setSize(sf::Vector2f(100 - dashCooldown_ * 50, 30));

    if (!font_.loadFromFile("content/fonts/arial.ttf")) {
        std::cout << "load failed" << std::endl;
    }
}

void Gamebar::Render(sf::RenderTarget* target)
{
    //target->draw(background_);
    target->draw(redBar_);
    target->draw(greenBar_);
    target->draw(violetBar_);
    target->draw(yellowBar_);

    sf::Text hp;
    hp.setFont(font_);
    hp.setString(std::to_string(hitpoints_));
    hp.setCharacterSize(15);
    hp.setPosition(40, 30);
    hp.setFillColor(sf::Color::White);

    target->draw(hp);
}

void Gamebar::Update()
{
    int newGreenWidth = std::min(100, std::max(0, 2 * (player_->GetHitPoints())));
    greenBar_.setSize(sf::Vector2f(newGreenWidth, 30));

    int newVioletWidth = 100 - 100 * (player_->GetAttackCooldownLeft() / player_->GetAttackCooldownLength());
    violetBar_.setSize(sf::Vector2f(newVioletWidth, 30));

    int newYellowWidth = 100 - 100 * (player_->GetDashCooldownLeft() / player_->GetDashCooldownLength());
    yellowBar_.setSize(sf::Vector2f(newYellowWidth, 30));
}
