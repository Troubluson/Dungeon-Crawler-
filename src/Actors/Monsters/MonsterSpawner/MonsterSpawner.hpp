#pragma once
#ifndef _MONSTERSPAWNER_CLASS_
#define _MONSTERSPAWNER_CLASS_
#include "../RandomMonster.hpp"
#include "../SearchingMonster.hpp"

typedef std::shared_ptr<Monster> monsterSP;

class MonsterSpawner {

public:
    MonsterSpawner(uint monsterAmount)
        : monsterCount_(monsterAmount)
    {
    }
    MonsterSpawner()
        : monsterCount_(0) {};

    ~MonsterSpawner() { }

    // std::list<Monster*> SpawnMonsters(sf::Vector2u roomSize) const;
    monsterSP SpawnMonster(sf::Vector2u roomSize, PlayerPS target) const;
    void SetMonsterAmount(uint amount);
    uint GetMonsterAmount() const;

private:
    monsterSP getRandomMonster(PlayerPS target) const;
    uint monsterCount_;
    uint monsterClassCount_ = 2; // update this when adding monsters
};

#endif
