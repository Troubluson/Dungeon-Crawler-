#include "WallPatrolMonster.hpp"
namespace {
const std::string projectileSprite = "content/sprites/monster1.png";
}

WallPatrolMonster::WallPatrolMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos, projectileSprite)
{
    initVariables();
}
WallPatrolMonster::WallPatrolMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), projectileSprite)
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
    if (!movedLastTick) {
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

std::list<Projectile*> WallPatrolMonster::Attack()
{
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(player_->GetSpriteCenter());
}

void WallPatrolMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}