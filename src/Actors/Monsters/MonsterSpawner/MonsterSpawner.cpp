#include "MonsterSpawner.hpp"
#include <time.h>

MonsterSP MonsterSpawner::getRandomMonster(PlayerPS target) const
{
    int monsterType = randomhelper::RandomIntBetween(0, monsterTypeCount_ - 1);
    switch (monsterType) {
    case 0: { // RandomMonster
        return MonsterSP(new RandomMonster(target, 0, 0));
    }
    case 1: { // SlowMonster

        return MonsterSP(new SlowMonster(target, 1000, 700));
    }
    case 2: { // WallPatrolMonster
        return MonsterSP(new WallPatrolMonster(target, 1000, 700));
    }
    case 3: { // SnipingMonster
        return MonsterSP(new SnipingMonster(target, 0, 0));
    }
    case 4:
        return MonsterSP(new SearchingMonster(target, 0, 0));
    default:
        return nullptr;
    }
}

MonsterSP MonsterSpawner::SpawnMonster(sf::Vector2u roomSize, PlayerPS target) const
{
    auto m = getRandomMonster(target);
    if (m == nullptr) {
        return nullptr;
    }
    int randomPosX, randomPosY;
    randomPosX = (rand() % (roomSize.x - 200)) + 100;
    randomPosY = (rand() % (roomSize.y - 200)) + 100;
    m->SetPosAndOldPos(sf::Vector2f(randomPosX, randomPosY));
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
