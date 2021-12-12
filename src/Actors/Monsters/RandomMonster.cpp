#include "RandomMonster.hpp"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monsters/monster1.png";
}

RandomMonster::RandomMonster(PlayerPS player, sf::Vector2f pos)
    : Monster(player, pos, monsterSpriteFileLocation)
{
}
RandomMonster::RandomMonster(PlayerPS player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

RandomMonster::~RandomMonster() { }

bool RandomMonster::Move(float dt)
{
    elapsedTurnTime_ += dt;
    if (elapsedTurnTime_ > durationUntilTurn_ || !movedLastTick_) {
        elapsedTurnTime_ = 0.0f;
        currentDir_ = randomhelper::RandomIntBetween(1, 4);
        durationUntilTurn_ = randomhelper::RandomFloatBetween(0.2f, 1.0f);
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

std::list<ProjectileUP> RandomMonster::Attack()
{
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer() || !IsAlive()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(player_->GetSpriteCenter());
}

void RandomMonster::initVariables()
{
    SwordWeapon* monsterSword = new SwordWeapon(5, 100, 120, 1000, sf::Vector2f(120, 120), "content/sprites/Weapons/spear.png");
    Equip(monsterSword);
    SetNormalSpeed(200.0f);
}