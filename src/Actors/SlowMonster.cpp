#include "SlowMonster.hpp"
namespace {
const std::string projectileSprite = "content/sprites/monster1.png";
}

SlowMonster::SlowMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos, projectileSprite)
{
    initVariables();
}
SlowMonster::SlowMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), projectileSprite)
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

    sf::Vector2f playerCenterPos = player_->GetSpriteCenter();
    float xMiss = RandomFloatBetween(-120.0f, 120.0f);
    float yMiss = RandomFloatBetween(-120.0f, 120.0f);
    sf::Vector2f aimPos1 = sf::Vector2f(playerCenterPos.x + xMiss, playerCenterPos.y + yMiss);

    std::list<Projectile*> list1 = shotProjectileList(aimPos1);

    return list1;
}

void SlowMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}