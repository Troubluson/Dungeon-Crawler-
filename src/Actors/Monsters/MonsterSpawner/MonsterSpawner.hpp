#pragma once
#ifndef _MONSTERSPAWNER_CLASS_
#define _MONSTERSPAWNER_CLASS_
#include "../RandomMonster.hpp"
#include "../SearchingMonster.hpp"
#include "roomInstance.hpp"

class MonsterSpawner {
public:
    MonsterSpawner(Player* character, RoomInstance& spawnRoom, uint monsterAmount);
    std::list<Monster*> SpawnMonsters() const;
    Monster* SpawnMonster() const;
    ~MonsterSpawner() { }

private:
    Monster* getRandomMonster() const;
    Player* character_; // target
    RoomInstance& spawnRoom_;
    uint monsterCount_;
    uint monsterClassCount_ = 2; // update this when adding monsters
};

#endif
