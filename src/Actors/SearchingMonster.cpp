#include "SearchingMonster.hpp"

SearchingMonster::SearchingMonster(Player* player, sf::Vector2f pos)
    : Monster(pos)
    , player_(player)
{
}
SearchingMonster::SearchingMonster(Player* player, float xPos, float yPos)
    : Monster(sf::Vector2f(xPos, yPos))
    , player_(player)

{
}

SearchingMonster::~SearchingMonster() { }

void SearchingMonster::Move(float dt)
{
    sf::Vector2f playerpos = player_->GetSpriteCenter();
    sf::Vector2f distanceVec = playerpos - GetSpriteCenter();
    float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
    sf::Vector2f velocityVec = distanceVec / distance;
    MoveRight(dt * velocityVec.x * 0.8);
    MoveDown(dt * velocityVec.y * 0.8);
}

void SearchingMonster::MonsterAttack(Player& player)
{
    if (cooldown_.getElapsedTime().asSeconds() > 2) {
        cooldown_.restart();
        sf::Vector2f playerPos = player.GetSpriteCenter();
        sf::Vector2f distanceVec = playerPos - GetSpriteCenter();
        float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
        if (distance < 50) {
            player.TakeDamage(10);
        }
    }
}