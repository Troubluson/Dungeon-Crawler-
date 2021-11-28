#include "Actors/monster.hpp"

Monster::Monster(sf::Vector2f pos)
    : Character("content/monster1.png", pos)
{
}
Monster::Monster(float xPos, float yPos)
    : Character("content/monster1.png", sf::Vector2f(xPos, yPos))
{
}

Monster::~Monster()
{
}

void Monster::Move(float dt)
{
    int dir = rand() % 4 + 1;
    if (dir == 1) {
        MoveDown(dt);
    } else if (dir == 2) {
        MoveLeft(dt);
    } else if (dir == 3) {
        MoveUp(dt);
    } else
        MoveRight(dt);
}