#include "MonsterSpawner.hpp"
#include <time.h>

MonsterSpawner::MonsterSpawner(Player* player, RoomInstance& spawnRoom, uint monsterAmount)
    : character_(player)
    , spawnRoom_(spawnRoom)
    , monsterCount_(monsterAmount)
{
    srand(sf::Mouse::getPosition().x);
}
Monster* MonsterSpawner::getRandomMonster() const
{
    int monsterType = rand() % monsterClassCount_;
    switch (monsterType) {
    case 0: {
        SwordWeapon* monterSword = new SwordWeapon(5, 10, sf::Vector2f(50, 100), 120, "content/sprites/projectiles.png");
        auto m = new RandomMonster(character_, 0, 0);
        m->Equip(monterSword);
        return m;
    }
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
    int randomPosX, randomPosY;
    sf::Vector2u roomSize = spawnRoom_.getRoomSize();
    do {
        randomPosX = (rand() % (roomSize.x - 200)) + 100;
        randomPosY = (rand() % (roomSize.y - 200)) + 100;
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
