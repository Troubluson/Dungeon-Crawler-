#include "monster.hpp"

Monster::Monster(sf::Vector2f pos)
    : Character("content/monster1.png", pos)
{
}

void Monster::Move()
{
    int dir = rand() % 4 + 1;
    if (dir == 1) {
        MoveDown();
    } else if (dir == 2) {
        MoveLeft();
    } else if (dir == 3) {
        MoveUp();
    } else
        MoveRight();
}