#include "RandomMonster.hpp"
namespace {
const std::string projectileSprite = "content/sprites/monster1.png";
}

RandomMonster::RandomMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos, projectileSprite)
{
}
RandomMonster::RandomMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), projectileSprite)
{
}

RandomMonster::~RandomMonster() { }

bool RandomMonster::Move(float dt)
{
    elapsedTurnTime += dt;
    if (elapsedTurnTime > durationUntilTurn || !movedLastTick) {
        elapsedTurnTime = 0.0f;
        currentDir_ = RandomIntBetween(1, 4);
        durationUntilTurn = RandomFloatBetween(0.2f, 1.0f);
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

std::list<Projectile*> RandomMonster::Attack()
{
    if (!CanAttack || !HasWeapon()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(player_->GetSpriteCenter());
}