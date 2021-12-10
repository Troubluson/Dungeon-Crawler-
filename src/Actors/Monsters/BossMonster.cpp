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
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer()) {
        return emptyList();
    }

    ResetAttackCooldown();
    if (attackStyle == 0) {
        std::list<Projectile*> listOfBulletsToAdd;
        int i = 0;
        int nofBullets = 10;
        sf::Vector2f centerPos = player_.GetSpriteCenter();
        float angle = 0;
        while (i < nofBullets) {
            sf::Vector2f shootPos = sf::Vector2f(centerPos.x + 1000 * sin(angle), centerPos.y - 1000 * cos(angle));
            std::list<Projectile*> subListToAdd = shotProjectileList(shootPos);
            listOfBulletsToAdd.merge(subListToAdd);
            fullAttackVector.push_back(*listOfBulletsToAdd.begin());
            angle += 2 * M_PI / nofBullets;
            i += 1;
        }
        return listOfBulletsToAdd;
    }
    return emptyList();
}

void BossMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}