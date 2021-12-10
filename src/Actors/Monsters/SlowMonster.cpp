#include "SlowMonster.hpp"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monster1.png";
}

SlowMonster::SlowMonster(Player& player, sf::Vector2f pos)
    : SlowMonster(player, pos.x, pos.y)
{
}
SlowMonster::SlowMonster(Player& player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

SlowMonster::~SlowMonster() { }

bool SlowMonster::Move(float dt)
{
    return moveTowardsPlayer(dt);
}

std::list<Projectile*> SlowMonster::Attack()
{
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer()) {
        return emptyList();
    }

    ResetAttackCooldown();

    sf::Vector2f playerCenterPos = player_.GetSpriteCenter();
    float xMiss = randomhelper::RandomFloatBetween(-120.0f, 120.0f);
    float yMiss = randomhelper::RandomFloatBetween(-120.0f, 120.0f);
    sf::Vector2f aimPos1 = sf::Vector2f(playerCenterPos.x + xMiss, playerCenterPos.y + yMiss);

    std::list<Projectile*> list1 = shotProjectileList(aimPos1);

    return list1;
}

void SlowMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}