#include "MonsterSpawner.hpp"
#include <time.h>

monsterSP MonsterSpawner::getRandomMonster(PlayerPS target) const
{
    int monsterType = rand() % monsterClassCount_;
    switch (monsterType) {
    case 0: {
        SwordWeapon* monterSword = new SwordWeapon(5, 10, sf::Vector2f(50, 100), 120, "content/sprites/projectiles.png");
        monsterSP m(new RandomMonster(target, 0, 0));
        m->Equip(monterSword);
        return m;
    }
    case 1:
        return monsterSP(new SearchingMonster(target, 0, 0));
    default:
        return nullptr;
    }
}

monsterSP MonsterSpawner::SpawnMonster(sf::Vector2u roomSize, PlayerPS target) const
{
    auto m = getRandomMonster(target);
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

void MonsterSpawner::SetMonsterAmount(uint amount)
{
    monsterCount_ = amount;
}

uint MonsterSpawner::GetMonsterAmount() const
{
    return monsterCount_;
}
