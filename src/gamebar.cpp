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

    spritehelper::CreateSpriteFrom("content/sprites/potions/red_potion.png", sf::Vector2f(0.4, 0.4), redsprite_, redtexture_);
    spritehelper::CreateSpriteFrom("content/sprites/potions/green_potion.png", sf::Vector2f(0.4, 0.4), greensprite_, greentexture_);
    spritehelper::CreateSpriteFrom("content/sprites/potions/yellow_potion.png", sf::Vector2f(0.4, 0.4), yellowsprite_, yellowtexture_);
    spritehelper::CreateSpriteFrom("content/sprites/potions/violet_potion.png", sf::Vector2f(0.4, 0.4), violetsprite_, violettexture_);

    redsprite_.setPosition(redpos_);
    greensprite_.setPosition(greenpos_);
    yellowsprite_.setPosition(yellowpos_);
    violetsprite_.setPosition(violetpos_);
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

    RenderInventory(target);
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

void Gamebar::RenderInventory(sf::RenderTarget* target)
{
    std::vector<Potion*> inv = player_->GetInventory();

    int red = 0;
    int green = 0;
    int yellow = 0;
    int violet = 0;

    for (auto i : inv) {
        if (i->GetColour() == "red")
            red += 1;
        else if (i->GetColour() == "green")
            green += 1;
        else if (i->GetColour() == "yellow")
            yellow += 1;
        else if (i->GetColour() == "violet")
            violet += 1;
    }
    sf::Text nofred;
    sf::Text nofgreen;
    sf::Text nofyellow;
    sf::Text nofviolet;

    nofred.setString("x" + std::to_string(red));
    nofgreen.setString("x" + std::to_string(green));
    nofyellow.setString("x" + std::to_string(yellow));
    nofviolet.setString("x" + std::to_string(violet));

    std::vector<sf::Text> amounts;
    amounts.push_back(nofred);
    amounts.push_back(nofgreen);
    amounts.push_back(nofyellow);
    amounts.push_back(nofviolet);

    float xcoord = 0;

    for (auto a : amounts) {
        a.setFont(font_);
        a.setCharacterSize(25);
        a.setPosition(820 + xcoord, 5);
        a.setFillColor(sf::Color::White);
        target->draw(a);
        xcoord += 100;
    }

    target->draw(redsprite_);
    target->draw(greensprite_);
    target->draw(yellowsprite_);
    target->draw(violetsprite_);
}
