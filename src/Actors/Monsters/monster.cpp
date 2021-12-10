#include "monster.hpp"

Monster::Monster(Player& player, sf::Vector2f pos, const std::string& spriteFile)
    : Character(spriteFile, pos)
    , player_(player)
{
    initVariables();
    sf::RectangleShape healthbar(sf::Vector2f(100, 5));
    healthbar.setFillColor(sf::Color::Green);
    healthbar.setPosition(pos.x + 15, pos.y - 5);
    healthbar_ = healthbar;
}
Monster::Monster(Player& player, float xPos, float yPos, const std::string& spriteFile)
    : Monster(player, sf::Vector2f(xPos, yPos), spriteFile)
{
}
void Monster::initVariables()
{
    characterProjectileType = Projectile::Type::EnemyProjectile;
}

void Monster::SetTarget(Player& target)
{
    player_ = target;
}

Monster::~Monster()
{
}

void Monster::Render(sf::RenderTarget* target)
{
    target->draw(GetSprite());
    target->draw(healthbar_);
}

Player& Monster::GetPlayer() const
{
    return player_;
}
void Monster::Update(float dt)
{
    generalUpdate(dt);
    int width = hitpoints_;
    int newWidth = std::min(100, std::max(0, width));
    healthbar_.setSize(sf::Vector2f(newWidth, 5));
    healthbar_.setPosition(GetPos() + sf::Vector2f(15, -5));
}

float Monster::getDistanceToPlayer()
{
    sf::Vector2f playerpos = GetPlayer().GetSpriteCenter();
    sf::Vector2f distanceVec = playerpos - GetSpriteCenter();
    float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
    return distance;
}
