#pragma once
#ifndef _MONSTERSPAWNER_CLASS_
#define _MONSTERSPAWNER_CLASS_
#include "../BossMonster.hpp"
#include "../RandomMonster.hpp"
#include "../SearchingMonster.hpp"
#include "../SlowMonster.hpp"
#include "../SnipingMonster.hpp"
#include "../WallPatrolMonster.hpp"

typedef std::shared_ptr<Monster> MonsterSP;

class MonsterSpawner {

public:
    MonsterSpawner(uint monsterAmount)
        : monsterCount_(monsterAmount)
    {
    }
    MonsterSpawner()
        : monsterCount_(0) {};

    virtual ~MonsterSpawner() { }

    // std::list<Monster*> SpawnMonsters(sf::Vector2u roomSize) const;
    virtual MonsterSP SpawnMonster(sf::Vector2u roomSize, PlayerPS target) const;
    void SetMonsterAmount(uint amount);
    uint GetMonsterAmount() const;

protected:
    MonsterSP getRandomMonster(PlayerPS target) const;
    uint monsterCount_;
    uint monsterTypeCount_ = 5; // update this when adding monsters
};

typedef std::shared_ptr<MonsterSpawner> MonsterSpawnerUP;

#endif
