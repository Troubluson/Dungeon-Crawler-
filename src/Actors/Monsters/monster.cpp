#include "monster.hpp"

Monster::Monster(PlayerPS player, sf::Vector2f pos, const std::string& spriteFile)
    : Character(spriteFile, pos)
    , player_(player)
{
    initVariables();
    sf::RectangleShape healthbar(sf::Vector2f(100, 5));
    healthbar.setFillColor(sf::Color::Green);
    healthbar.setPosition(pos.x + 15, pos.y - 5);
    healthbar_ = healthbar;
}
Monster::Monster(PlayerPS player, float xPos, float yPos, const std::string& spriteFile)
    : Monster(player, sf::Vector2f(xPos, yPos), spriteFile)
{
}
void Monster::initVariables()
{
    movedLastTick_ = false;
    characterProjectileType_ = Projectile::Type::EnemyProjectile;
}

void Monster::SetTarget(PlayerPS target)
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
    return *player_;
}
void Monster::Update(float dt)
{
    movedLastTick_ = true;
    if (oldPos_.x == pos_.x && oldPos_.y == pos_.y) {
        movedLastTick_ = false;
    }
    generalUpdate(dt);

    int width = hitpoints_;
    int newWidth = std::min(100, std::max(0, width));
    healthbar_.setSize(sf::Vector2f(newWidth, 5));
    healthbar_.setPosition(GetPos() + sf::Vector2f(15, -5));

    clampPosToRoom();
}

void Monster::clampPosToRoom()
{
    float max_x = 1130.0f;
    float min_x = 70.0f;
    if (pos_.x > max_x) {
        SetPos(sf::Vector2f(max_x, pos_.y));
    } else if (pos_.x < min_x) {
        SetPos(sf::Vector2f(min_x, pos_.y));
    }

    float max_y = 620.0f;
    float min_y = 100.0f;
    if (pos_.y > max_y) {
        SetPos(sf::Vector2f(pos_.x, max_y));
    } else if (pos_.y < min_y) {
        SetPos(sf::Vector2f(pos_.x, min_y));
    }
}

float Monster::getDistanceToPlayer()
{
    sf::Vector2f playerpos = GetPlayer().GetSpriteCenter();
    sf::Vector2f distanceVec = playerpos - GetSpriteCenter();
    float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
    return distance;
}

Potion* Monster::ReturnPotion()
{
    sf::Vector2f currentPos = GetPos();
    int r = randomhelper::RandomIntBetween(0, 18);
    if (r < 4 && r > -1)
        return new GreenPotion(currentPos);
    else if (r < 8 && r > 3)
        return new RedPotion(currentPos);
    else if (r < 10 && r > 7)
        return new YellowPotion(currentPos);
    else if (r < 12 && r > 9)
        return new VioletPotion(currentPos);
    else
        return nullptr;
}
bool Monster::inRangeOfPlayer()
{
    if (!HasWeapon()) {
        return true;
    }

    if (getDistanceToPlayer() < (weapon_->GetRange()) + 100) {
        return true;
    }

    return false;
}

bool Monster::moveTowardsPlayer(float dt)
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
