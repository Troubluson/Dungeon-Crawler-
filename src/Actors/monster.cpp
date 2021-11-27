#include "monster.hpp"

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
