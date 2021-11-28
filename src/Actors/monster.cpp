#include "monster.hpp"

Monster::Monster(Player* player, sf::Vector2f pos)
    : Character("content/monster1.png", pos)
    , player_(player)
{
}
Monster::Monster(Player* player, float xPos, float yPos)
    : Character("content/monster1.png", sf::Vector2f(xPos, yPos))
    , player_(player)
{
}

Monster::~Monster()
{
}
Player& Monster::GetPlayer() const
{
    return *player_;
}
void Monster::Update(float dt)
{
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