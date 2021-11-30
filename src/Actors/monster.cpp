#include "Actors/monster.hpp"

Monster::Monster(Player* player, sf::Vector2f pos)
    : Character("content/monster1.png", pos)
    , player_(player)
{
    sf::RectangleShape healthbar(sf::Vector2f(100, 5));
    healthbar.setFillColor(sf::Color::Green);
    healthbar.setPosition(pos.x + 15, pos.y - 5);
    healthbar_ = healthbar;
}
Monster::Monster(Player* player, float xPos, float yPos)
    : Character("content/monster1.png", sf::Vector2f(xPos, yPos))
    , player_(player)
{
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

std::list<Projectile*> Monster::FireWeapon(sf::Vector2f aimPosition)
{
    std::list<Projectile*> list = generateShootingProjectiles(aimPosition);
    for (auto it : list) {
        it->SetType(Projectile::Type::EnemyProjectile);
    }

    return list;
}

void Monster::Update(float)
{
    int width = hitpoints_;
    int newWidth = std::min(100, std::max(0, width));
    healthbar_.setSize(sf::Vector2f(newWidth, 5));
    healthbar_.setPosition(GetPos() + sf::Vector2f(15, -5));

    sprite_.setPosition(pos_);
    if (hitpoints_ <= 0) {
        alive_ = false;
    }
}