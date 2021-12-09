#pragma once
#ifndef _MONSTERSPAWNER_CLASS_
#define _MONSTERSPAWNER_CLASS_
#include "../RandomMonster.hpp"
#include "../SearchingMonster.hpp"

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
    Monster* SpawnMonster(sf::Vector2u roomSize, Player& target) const;
    void SetMonsterAmount(uint amount);
    uint GetMonsterAmount() const;

private:
    Monster* getRandomMonster(Player& target) const;
    uint monsterCount_;
    uint monsterClassCount_ = 2; // update this when adding monsters
};

#endif
