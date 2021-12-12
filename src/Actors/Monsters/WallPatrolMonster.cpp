#include "WallPatrolMonster.hpp"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monster5.png";
}

WallPatrolMonster::WallPatrolMonster(PlayerPS player, sf::Vector2f pos)
    : WallPatrolMonster(player, pos.x, pos.y)
{
}
WallPatrolMonster::WallPatrolMonster(PlayerPS player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

WallPatrolMonster::~WallPatrolMonster() { }

void WallPatrolMonster::changeDirection()
{
    if (currentDir_ == 4) {
        currentDir_ = 1;
    } else if (currentDir_ == 1) {
        currentDir_ = 2;
    } else if (currentDir_ == 2) {
        currentDir_ = 3;
    } else {
        currentDir_ = 4;
    }
}
bool WallPatrolMonster::Move(float dt)
{
    if (!movedLastTick_) {
        changeDirection();
    }
    if (currentDir_ == 1) {
        MoveDown(dt);
    } else if (currentDir_ == 2) {
        MoveLeft(dt);
    } else if (currentDir_ == 3) {
        MoveUp(dt);
    } else {
        MoveRight(dt);
    }
    return true;
}

std::list<ProjectileUP> WallPatrolMonster::Attack()
{
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(player_->GetSpriteCenter());
}

void WallPatrolMonster::initVariables()
{
    SwordWeapon* monsterSword = new SwordWeapon(5, 100, 120, 1000, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
    Equip(monsterSword);
    SetNormalSpeed(200.0f);
}