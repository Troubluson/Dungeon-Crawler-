#include "MonsterSpawner.hpp"
#include <time.h>

Monster* MonsterSpawner::getRandomMonster(Player& target) const
{
    SwordWeapon* monterSword = new SwordWeapon(5, 100, 120, 1000, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
    Monster* m = new BossMonster(target, 200, 200);
    m->Equip(monterSword);
    return m;

    /* int monsterAttackType = rand() % monsterAttackTypeCount_;
    switch (monsterAttackType) {
    case 0: { //RandomMonster
        SwordWeapon* monterSword = new SwordWeapon(5, 100, 120, 1000, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
        Monster* m = new RandomMonster(target, 0, 0);
        m->Equip(monterSword);
        return m;
        break;
    }
    case 1: { //SlowMonster
        BowWeapon* slowBow = new BowWeapon(5, 400, 200, 200, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
        Monster* m = new SlowMonster(target, 1000, 700);
        m->Equip(slowBow);
        return m;
        break;
    }
    case 2: { //WallPatrolMonster
        SwordWeapon* monterSword = new SwordWeapon(5, 100, 120, 1000, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
        Monster* m = new WallPatrolMonster(target, 1000, 700);
        m->Equip(monterSword);
        return m;
        break;
    }
    case 3: { //SnipingMonster
        BowWeapon* snipingBow = new BowWeapon(5, 10000, 30, 1000, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
        Monster* m = new SnipingMonster(target, 0, 0);
        m->Equip(snipingBow);
        return m;
        break;
    }
    case 4:
        return new SearchingMonster(target, 0, 0);
    default:
        return nullptr;
    } */
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
    m->SetPosAndOldPos(sf::Vector2f(randomPosX, randomPosY));
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
