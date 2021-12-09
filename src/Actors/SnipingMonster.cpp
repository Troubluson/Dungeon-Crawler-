#include "SnipingMonster.hpp"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monster1.png";
}

SnipingMonster::SnipingMonster(Player* player, sf::Vector2f pos)
    : SnipingMonster(player, pos.x, pos.y)
{
}
SnipingMonster::SnipingMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

SnipingMonster::~SnipingMonster() { }

bool SnipingMonster::Move(float)
{
    return false; //Should never move
}

std::list<Projectile*> SnipingMonster::Attack()
{
    if (!CanAttack || !HasWeapon() || !inRangeOfPlayer()) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(player_->GetSpriteCenter());
}

void SnipingMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}