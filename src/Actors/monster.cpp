#include "Actors/monster.hpp"

Monster::Monster(Player* player, sf::Vector2f pos)
    : Character("content/monster1.png", pos)
    , player_(player)
{
    sf::RectangleShape greenbar(sf::Vector2f(100, 5));
    greenbar.setFillColor(sf::Color::Green);
    greenbar.setPosition(pos.x + 15, pos.y - 5);
    greenbar_ = greenbar;
}
Monster::Monster(Player* player, float xPos, float yPos)
    : Character("content/monster1.png", sf::Vector2f(xPos, yPos))
    , player_(player)
{
}

Monster::~Monster()
{
}

void Monster::Render(sf::RenderTarget* target)
{
    target->draw(GetSprite());
    target->draw(greenbar_);
}

Player& Monster::GetPlayer() const
{
    return *player_;
}
void Monster::Update(float dt)
{
    int width = hitpoints_;
    int newWidth = std::min(100, std::max(0, width));
    greenbar_.setSize(sf::Vector2f(newWidth, 5));
    greenbar_.setPosition(GetPos() + sf::Vector2f(15, -5));

    Move(dt);
    sprite_.setPosition(pos_);
    if (hitpoints_ <= 0) {
        alive_ = false;
    }
    pos_.x = clamp(pos_.x, 50, 1050);
    pos_.y = clamp(pos_.y, 0, 550);

    MonsterAttack();

    oldPos_ = pos_;
}