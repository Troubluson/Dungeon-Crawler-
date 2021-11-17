#include "monster.hpp"

template <typename T>
T Vector2length(const sf::Vector2<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Monster::Monster(float xPos, float yPos)
    : Character("content/monster1.png", xPos, yPos)
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

void Monster::Attack(Player player)
{
    sf::Vector2f playerPos = player.GetPosition();
    sf::Vector2f monsterPos = GetPosition();
    if (Vector2length(playerPos - monsterPos) < 20 && Vector2length(playerPos - monsterPos) > -20) {
        player.ReduceHitpoints();
    }
}