#include "MonsterSpawner.hpp"
#include <time.h>

Monster* MonsterSpawner::getRandomMonster(Player& target) const
{
    int monsterAttackType = rand() % monsterAttackTypeCount;
    switch (monsterAttackType) {
    case 0: {
        int projectilemonsterType = rand() % projectilemonsterClassCount_;
        Monster* m = nullptr;
        switch (projectilemonsterType) {
        case 0: { //RandomMonster
            SwordWeapon* monterSword = new SwordWeapon(5, 100, sf::Vector2f(50, 100), 120, 1000, "content/sprites/projectiles.png");
            m = new RandomMonster(target, 0, 0);
            m->Equip(monterSword);
            break;
        }
        case 1: { //SnipingMonster
            BowWeapon* snipingBow = new BowWeapon(5, 10000, sf::Vector2f(50, 100), 30, 1000, "content/sprites/projectiles.png");
            m = new SnipingMonster(target, 0, 0);
            m->Equip(snipingBow);
            break;
        }
        case 2: { //SlowMonster
            BowWeapon* slowBow = new BowWeapon(5, 400, sf::Vector2f(50, 100), 200, 200, "content/sprites/projectiles.png");
            m = new SlowMonster(target, 1000, 700);
            m->Equip(slowBow);
            break;
        }
        case 3: {
            SwordWeapon* monterSword = new SwordWeapon(5, 100, sf::Vector2f(50, 100), 120, 1000, "content/sprites/projectiles.png");
            m = new WallPatrolMonster(target, 1000, 700);
            m->Equip(monterSword);
            break;
        }
        default:
            return nullptr;
        }

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
