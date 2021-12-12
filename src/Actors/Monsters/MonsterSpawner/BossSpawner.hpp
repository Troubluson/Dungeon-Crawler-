#pragma once
#ifndef _BOSS_SPAWNER_CLASS_
#define _BOSS_SPAWNER_CLASS_
#include "../BossMonster.hpp"
#include "MonsterSpawner.hpp"

class BossSpawner : public MonsterSpawner {
public:
    BossSpawner()
        : MonsterSpawner(1)
    {
    }

    ~BossSpawner() { }
    MonsterSP SpawnMonster(sf::Vector2u roomSize, PlayerPS target);
};

#endif