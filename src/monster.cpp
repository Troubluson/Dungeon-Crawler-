#include "monster.hpp"

Monster::Monster(float xPos, float yPos)
    : Character("content/monster1.png", xPos, yPos)
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