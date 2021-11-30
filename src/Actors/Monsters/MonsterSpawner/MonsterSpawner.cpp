#include "MonsterSpawner.hpp"
#include <time.h>

MonsterSpawner::MonsterSpawner(Player* player, RoomInstance& spawnRoom, uint monsterAmount)
    : character_(player)
    , spawnRoom_(spawnRoom)
    , monsterCount_(monsterAmount)
{
}
Monster* MonsterSpawner::getRandomMonster() const
{
    srand(time(0));
    int monsterType = rand() % monsterClassCount_;
    switch (monsterType) {
    case 0:
        return new RandomMonster(character_, 0, 0);
    case 1:
        return new SearchingMonster(character_, 0, 0);
    default:
        return nullptr;
    }
}
Monster* MonsterSpawner::SpawnMonster() const
{
    srand(time(0));
    Monster* m = getRandomMonster();
    if (m == nullptr) {
        std::cout << "nullptr";
        return nullptr;
    }
    int randomPosX, randomPosY;
    sf::Vector2u roomSize = spawnRoom_.getRoomSize();
    do {
        randomPosX = (rand() % (roomSize.x - 100)) + 100;
        randomPosY = (rand() % (roomSize.y - 100)) + 100;
        m->setOldAndNewPos(sf::Vector2f(randomPosX, randomPosY));

    } while (!spawnRoom_.positionIsWalkable(m->GetBaseBoxAt(m->GetPos())));
    return m;
}

std::list<Monster*> MonsterSpawner::SpawnMonsters() const
{
    std::list<Monster*> monsters;
    for (auto i = 0u; i < monsterCount_; ++i) {
        Monster* newMonster = SpawnMonster();
        if (newMonster == nullptr) {
            return std::list<Monster*>();
        }
        monsters.push_back(newMonster);
    }
    return monsters;
}
