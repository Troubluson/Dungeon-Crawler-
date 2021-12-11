#include "RandomMonster.hpp"
namespace {
const std::string projectileSprite = "content/sprites/monster1.png";
}

RandomMonster::RandomMonster(PlayerPS player, sf::Vector2f pos)
    : Monster(player, pos, projectileSprite)
    , currentDir_(0)
{
}
RandomMonster::RandomMonster(PlayerPS player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), projectileSprite)
    , currentDir_(0)
{
}

RandomMonster::~RandomMonster() { }

bool RandomMonster::Move(float dt)
{
    elapsedTurnTime += dt;
    oldPos_ = GetPos();
    if (elapsedTurnTime > 0.3) {
        elapsedTurnTime = 0.0f;
        int dir = rand() % 4;
        currentDir_ = dir;
    }
    if (currentDir_ == 0) {
        MoveDown(dt);
    } else if (currentDir_ == 1) {
        MoveLeft(dt);
    } else if (currentDir_ == 2) {
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