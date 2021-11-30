#pragma once
#ifndef _MONSTERSPAWNER_CLASS_
#define _MONSTERSPAWNER_CLASS_
#include "../RandomMonster.hpp"
#include "../SearchingMonster.hpp"

class MonsterSpawner {
public:
    MonsterSpawner(Character* character, uint monsterAmount);
    std::list<Monster*> SpawnMonsters() const;
    Monster* SpawnMonster() const;
    ~MonsterSpawner() { }

private:
    Monster* getRandomMonster() const;
    uint monsterCount_;
    uint monsterClassCount_ = 2; //update this when adding monsters
    Character* character_;
};

#endif
