#include "RandomMonster.hpp"

RandomMonster::RandomMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos)
{
}
RandomMonster::RandomMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos))
{
}

RandomMonster::~RandomMonster() { }

void RandomMonster::Move(float dt)
{
    float elapsedTime = clock_.getElapsedTime().asSeconds();
    if (elapsedTime > 0.3) {
        clock_.restart();
        int dir = rand() % 4 + 1;
        currentDir_ = dir;
    } else {
        if (currentDir_ == 1) {
            MoveDown(dt);
        } else if (currentDir_ == 2) {
            MoveLeft(dt);
        } else if (currentDir_ == 3) {
            MoveUp(dt);
        } else
            MoveRight(dt);
    }
}

void RandomMonster::MonsterAttack()
{
    GetPlayer().TakeDamage(0); //placeholder
}