#include "MonsterSpawner.hpp"
#include <time.h>

MonsterSpawner::MonsterSpawner(Player* character, uint monsterAmount)
    : monsterCount_(monsterAmount)
    , character_(character)
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
    auto randomPosX = (rand() % 500) + 100;
    auto randomPosY = (rand() % 300) + 100;
    m->setOldAndNewPos(sf::Vector2f(randomPosX, randomPosY));
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
