#include "SlowMonster.hpp"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monsters/monster4.png";
}

SlowMonster::SlowMonster(PlayerPS player, sf::Vector2f pos)
    : SlowMonster(player, pos.x, pos.y)
{
}
SlowMonster::SlowMonster(PlayerPS player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

SlowMonster::~SlowMonster() { }

bool SlowMonster::Move(float dt)
{
    return moveTowardsPlayer(dt);
}

std::list<ProjectileUP> SlowMonster::Attack()
{
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer() || !IsAlive()) {
        return emptyList();
    }

    ResetAttackCooldown();

    sf::Vector2f playerCenterPos = player_->GetSpriteCenter();
    float xMiss = randomhelper::RandomFloatBetween(-120.0f, 120.0f);
    float yMiss = randomhelper::RandomFloatBetween(-120.0f, 120.0f);
    sf::Vector2f aimPos1 = sf::Vector2f(playerCenterPos.x + xMiss, playerCenterPos.y + yMiss);
    shotProjectileList(aimPos1);
    return shotProjectileList(aimPos1);
    ;
}

void SlowMonster::initVariables()
{
    BowWeapon* slowBow = new BowWeapon(5, 400, 200, 200, sf::Vector2f(100, 100), "content/sprites/projectiles/projectileoctopus.png");
    Equip(slowBow);
    SetNormalSpeed(200.0f);
}