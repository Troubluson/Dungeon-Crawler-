#include "SearchingMonster.hpp"

SearchingMonster::SearchingMonster(Player* player, sf::Vector2f pos)
    : Monster(player, pos)
{
}
SearchingMonster::SearchingMonster(Player* player, float xPos, float yPos)
    : Monster(player, sf::Vector2f(xPos, yPos))
{
}

SearchingMonster::~SearchingMonster() { }

void SearchingMonster::Move(float dt)
{
    sf::Vector2f playerpos = GetPlayer().GetSpriteCenter();
    sf::Vector2f distanceVec = playerpos - GetSpriteCenter();
    float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
    sf::Vector2f velocityVec = distanceVec / distance;
    MoveRight(dt * velocityVec.x * 0.3);
    MoveDown(dt * velocityVec.y * 0.3);
}

void SearchingMonster::MonsterAttack()
{
    if (cooldown_.getElapsedTime().asSeconds() > 2) {
        sf::Vector2f playerPos = GetPlayer().GetSpriteCenter();
        sf::Vector2f distanceVec = playerPos - GetSpriteCenter();
        float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
        if (distance < 50) {
            cooldown_.restart();
            GetPlayer().TakeDamage(10);
        }
    }
}