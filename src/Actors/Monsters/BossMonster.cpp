#include "BossMonster.hpp"
#include "math.h"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monster1.png";
}

BossMonster::BossMonster(Player& player, sf::Vector2f pos)
    : Monster(player, pos, monsterSpriteFileLocation)
{
}
BossMonster::BossMonster(Player& player, float xPos, float yPos)
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

std::list<Projectile*> BossMonster::Attack()
{
    if ((!CanAttack || !HasWeapon()) && inRangeOfPlayer()) {
        return emptyList();
    }

    std::cout << "nofBulletsShot" << nofBulletsShot << std::endl;
    std::cout << "attackStyle_" << attackStyle_ << std::endl;

    sf::Vector2f centerPos = GetSpriteCenter();
    if (attackStyle_ == 0) {
        ResetAttackCooldown();
        std::list<Projectile*> listOfBulletsToAdd;
        while (nofBulletsShot < nofBulletsInCircle) {
            sf::Vector2f shootPos = sf::Vector2f(centerPos.x + 1 * sin(angle_), centerPos.y - 1 * cos(angle_));
            std::list<Projectile*> subListToAdd = shotProjectileList(shootPos);
            listOfBulletsToAdd.merge(subListToAdd);
            iterateAngle();
            nofBulletsShot += 1;
        }
        iterateAttackStyle();
        return listOfBulletsToAdd;
    } else if (attackStyle_ == 1) {
        if (attackLoopClock.getElapsedTime().asSeconds() >= spritalAttackCooldownLength) {
            attackLoopClock.restart();

            sf::Vector2f shootPos = sf::Vector2f(centerPos.x + 1 * sin(angle_), centerPos.y - 1 * cos(angle_));
            nofBulletsShot += 1;
            iterateAngle();
            if (nofBulletsShot == nofBulletsInCircle) {
                iterateAttackStyle();
                ResetAttackCooldown();
            }
            return shotProjectileList(shootPos);
        }
    } else if (attackStyle_ == 2) {
        if (attackLoopClock.getElapsedTime().asSeconds() >= normalAttackCooldownLength) {

            attackLoopClock.restart();
            nofBulletsShot += 1;
            if (nofBulletsShot == nofBulletsToShootTowardsPlayer) {
                iterateAttackStyle();
                ResetAttackCooldown();
            }
            return shotProjectileList(player_.GetSpriteCenter());
        }
    }

    return emptyList();
}

void BossMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}

void BossMonster::iterateAngle()
{
    angle_ += 2 * M_PI / nofBulletsInCircle;
    if (angle_ == 2 * M_PI) {
        angle_ = 0.0f;
    }
}

void BossMonster::iterateAttackStyle()
{
    nofBulletsShot = 0;
    attackStyle_ += 1;
    if (attackStyle_ == nofattackStyles_) {
        attackStyle_ = 0;
    }
}

/*

int i = 0;
int nofBullets = 10;
sf::Vector2f centerPos = player_.GetSpriteCenter();
float angle = 0;
while (i < nofBullets) {
    sf::Vector2f shootPos = sf::Vector2f(centerPos.x + 1000 * sin(angle), centerPos.y - 1000 * cos(angle));
    std::list<Projectile*> subListToAdd = shotProjectileList(shootPos);
    listOfBulletsToAdd.merge(subListToAdd);
    angle += 2 * M_PI / nofBullets;
    i += 1;
}

 */