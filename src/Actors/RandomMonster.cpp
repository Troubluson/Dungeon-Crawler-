#include "RandomMonster.hpp"

RandomMonster::RandomMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos)
{
}
RandomMonster::RandomMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos))
{
}

RandomMonster::~RandomMonster() { }

bool RandomMonster::Move(float dt)
{
    elapsedTurnTime += dt;
    oldPos_ = GetPos();
    if (elapsedTurnTime > 0.3) {
        elapsedTurnTime = 0.0f;
        int dir = rand() % 4 + 1;
        currentDir_ = dir;
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

std::list<Projectile*> RandomMonster::Attack()
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