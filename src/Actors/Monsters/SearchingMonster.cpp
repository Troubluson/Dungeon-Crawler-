#include "SearchingMonster.hpp"
namespace {
const std::string monsterSpriteFileLocation = "content/sprites/monster2.png";
}
SearchingMonster::SearchingMonster(Player& player, sf::Vector2f pos)
    : SearchingMonster(player, pos.x, pos.y)
{
    name = "Sir chi";
}
SearchingMonster::SearchingMonster(Player& player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), monsterSpriteFileLocation)
{
    initVariables();
}

SearchingMonster::~SearchingMonster() { }

bool SearchingMonster::Move(float dt)
{
    return moveTowardsPlayer(dt);
}

std::list<Projectile*> SearchingMonster::Attack()
{
    if (!CanAttack || getDistanceToPlayer() > 5.0f) {
        return emptyList();
    }

    ResetAttackCooldown();

    player_.TakeDamage(staticDamage);
    return emptyList();
}

void SearchingMonster::initVariables()
{
    SetNormalSpeed(200.0f);
}