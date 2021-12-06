#include "SearchingMonster.hpp"
namespace {
const std::string projectileSprite = "content/sprites/monster2.png";
}
SearchingMonster::SearchingMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos, projectileSprite)
{
    name = "Sir chi";
}
SearchingMonster::SearchingMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos), projectileSprite)
{
}

SearchingMonster::~SearchingMonster() { }

bool SearchingMonster::Move(float dt)
{
    sf::Vector2f playerpos = GetPlayer().GetSpriteCenter();
    sf::Vector2f distanceVec = playerpos - GetSpriteCenter();
    float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
    sf::Vector2f velocityVec = sf::Vector2f(0, 0);
    if (distance != 0.0f) {
        velocityVec = distanceVec / distance;
    }
    MoveRight(dt * velocityVec.x * 0.3);
    MoveDown(dt * velocityVec.y * 0.3);
    return true;
}

std::list<Projectile*> SearchingMonster::Attack()
{
    if (!CanAttack || getDistanceToPlayer() > 5.0f) {
        return emptyList();
    }

    ResetAttackCooldown();

    player_->TakeDamage(staticDamage);
    return emptyList();
}