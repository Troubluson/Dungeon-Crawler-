#include "MonsterSpawner.hpp"

MonsterSpawner::MonsterSpawner(Character* character, uint monsterAmount)
    : monsterCount_(monsterAmount)
    , character_(character)
{
}
Monster* MonsterSpawner::getRandomMonster() const
{
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
    Monster* m = getRandomMonster();
    if (m == nullptr) {
        std::cout << "nullptr";
        return nullptr;
    }
    auto randomPosX = rand() % 500 + 200;
    auto randomPosY = rand() % 300 + 200;
    m->setPos(sf::Vector2f(randomPosX, randomPosY));
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
