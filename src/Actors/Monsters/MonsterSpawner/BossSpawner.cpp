#include "BossSpawner.hpp"

MonsterSP BossSpawner::SpawnMonster(sf::Vector2u roomSize, PlayerPS target)
{
    MonsterSP m(new BossMonster(target, 0, 0));
    if (m == nullptr) {
        return nullptr;
    }
    int randomPosX, randomPosY;
    randomPosX = (rand() % (roomSize.x - 200)) + 100;
    randomPosY = (rand() % (roomSize.y - 200)) + 100;
    m->SetPosAndOldPos(sf::Vector2f(randomPosX, randomPosY));
    return m;
}
