#include "BossMonster.hpp"
#include "math.h"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monsters/ratking.png";
}

BossMonster::BossMonster(PlayerPS player, sf::Vector2f pos)
    : Monster(player, pos, monsterSpriteFileLocation)
{
}
BossMonster::BossMonster(PlayerPS player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

BossMonster::~BossMonster() { }

bool BossMonster::Move(float dt)
{
    elapsedTurnTime_ += dt;
    if (elapsedTurnTime_ > durationUntilTurn_ || !movedLastTick_) {
        elapsedTurnTime_ = 0.0f;
        currentDir_ = randomhelper::RandomIntBetween(1, 4);
        durationUntilTurn_ = randomhelper::RandomFloatBetween(0.2f, 1.0f);
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

std::list<ProjectileUP> BossMonster::Attack()
{
    if ((!CanAttack || !HasWeapon()) && inRangeOfPlayer()) {
        return emptyList();
    }

    sf::Vector2f centerPos = GetSpriteCenter();
    if (attackStyle_ == 0) {
        ResetAttackCooldown();
        std::list<ProjectileUP> listOfBulletsToAdd;
        while (nofBulletsShot_ < nofBulletsInCircle_) {
            sf::Vector2f shootPos = sf::Vector2f(centerPos.x + 1 * sin(angle_), centerPos.y - 1 * cos(angle_));
            std::list<ProjectileUP> subListToAdd = shotProjectileList(shootPos);
            listOfBulletsToAdd.merge(subListToAdd);
            iterateAngle();
            nofBulletsShot_ += 1;
        }
        iterateAttackStyle();
        return listOfBulletsToAdd;
    } else if (attackStyle_ == 1) {
        if (attackLoopClock_.getElapsedTime().asSeconds() >= spritalAttackCooldownLength_) {
            attackLoopClock_.restart();

            sf::Vector2f shootPos = sf::Vector2f(centerPos.x + 1 * sin(angle_), centerPos.y - 1 * cos(angle_));
            nofBulletsShot_ += 1;
            iterateAngle();
            if (nofBulletsShot_ == nofBulletsInCircle_) {
                iterateAttackStyle();
                ResetAttackCooldown();
            }
            return shotProjectileList(shootPos);
        }
    } else if (attackStyle_ == 2) {
        if (attackLoopClock_.getElapsedTime().asSeconds() >= normalAttackCooldownLength_) {

            attackLoopClock_.restart();
            nofBulletsShot_ += 1;
            if (nofBulletsShot_ == nofBulletsToShootTowardsPlayer_) {
                iterateAttackStyle();
                ResetAttackCooldown();
            }
            return shotProjectileList(player_->GetSpriteCenter());
        }
    }

    return emptyList();
}

void BossMonster::initVariables()
{
    SwordWeapon* bossSword = new SwordWeapon(10, 1000, 30, 200, sf::Vector2f(100, 100), "content/sprites/projectiles/projectileboss.png");
    Equip(bossSword);
    SetNormalSpeed(200.0f);
}

void BossMonster::iterateAngle()
{
    angle_ += 2 * M_PI / nofBulletsInCircle_;
    if (angle_ == 2 * M_PI) {
        angle_ = 0.0f;
    }
}

void BossMonster::iterateAttackStyle()
{
    nofBulletsShot_ = 0;
    attackStyle_ += 1;
    if (attackStyle_ == nofattackStyles_) {
        attackStyle_ = 0;
    }
}