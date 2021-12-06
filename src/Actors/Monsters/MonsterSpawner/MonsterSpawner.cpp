#include "MonsterSpawner.hpp"
#include <time.h>

Monster* MonsterSpawner::getRandomMonster(Player& target) const
{
    int monsterType = rand() % monsterClassCount_;
    switch (monsterType) {
    case 0: {
        SwordWeapon* monterSword = new SwordWeapon(5, 10, sf::Vector2f(50, 100), 120, "content/sprites/projectiles.png");
        auto m = new RandomMonster(target, 0, 0);
        m->Equip(monterSword);
        return m;
    }
    case 1:
        return new SearchingMonster(target, 0, 0);
    default:
        return nullptr;
    }
}
Monster* MonsterSpawner::SpawnMonster(sf::Vector2u roomSize, Player& target) const
{
    Monster* m = getRandomMonster(target);
    if (m == nullptr) {
        std::cout << "nullptr";
        return nullptr;
    }
    int randomPosX, randomPosY;
    randomPosX = (rand() % (roomSize.x - 200)) + 100;
    randomPosY = (rand() % (roomSize.y - 200)) + 100;
    m->setOldAndNewPos(sf::Vector2f(randomPosX, randomPosY));
    return m;
}

/*std::list<Monster*> MonsterSpawner::SpawnMonsters(sf::Vector2u roomSize) const
{
    std::list<Monster*> monsters;
    for (auto i = 0u; i < monsterCount_; ++i) {
        Monster* newMonster = SpawnMonster(roomSize, );
        if (newMonster == nullptr) {
            return std::list<Monster*>();
        }
        monsters.push_back(newMonster);
    }
    return monsters;
}*/
void MonsterSpawner::SetMonsterAmount(uint amount)
{
    monsterCount_ = amount;
}

uint MonsterSpawner::GetMonsterAmount() const
{
    return monsterCount_;
}
