#include "SnipingMonster.hpp"

SnipingMonster::SnipingMonster(Player* player, sf::Vector2f pos, const std::string& spriteFile)
    : Monster(player, pos, spriteFile)
{
}
SnipingMonster::SnipingMonster(Player* player, float xPos, float yPos, const std::string& spriteFile)
    : Monster(player, sf::Vector2f(xPos, yPos), spriteFile)
{
}

SnipingMonster::~SnipingMonster() { }

std::list<Projectile*> SnipingMonster::Attack()
{
    if (!CanAttack) {
        return emptyList();
    }

    if (weapon_ == nullptr) {
        return emptyList();
    }

    ResetAttackCooldown();

    return shotProjectileList(player_->GetSpriteCenter());
}

bool SnipingMonster::Move(float)
{
    return false;
}