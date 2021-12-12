#include "SearchingMonster.hpp"
namespace {
const std::string MONSTER_SPRITE_LOC = "content/sprites/monsters/monster2.png";
}
SearchingMonster::SearchingMonster(PlayerPS player, sf::Vector2f pos)
    : Monster(player, pos, MONSTER_SPRITE_LOC)
{
    name_ = "Sir chi";
}
SearchingMonster::SearchingMonster(PlayerPS player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), MONSTER_SPRITE_LOC)
{
    initVariables();
}

SearchingMonster::~SearchingMonster() { }

bool SearchingMonster::Move(float dt)
{
    return moveTowardsPlayer(dt);
}

std::list<ProjectileUP> SearchingMonster::Attack()
{
    if (!CanAttack || getDistanceToPlayer() > 5.0f || !IsAlive()) {
        return emptyList();
    }
    ResetAttackCooldown();

    player_->TakeDamage(staticDamage_);
    return emptyList();
}

void SearchingMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}