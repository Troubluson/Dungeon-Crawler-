#include "entity.hpp"

Entity::Entity(const std::string& filename, float xPos, float yPos)
{
    xPos_ = xPos;
    yPos_ = yPos;
    initSprite(filename);
    sprite_.setPosition(xPos, yPos);
}

void Entity::Render(sf::RenderTarget* target) { target->draw(sprite_); }

void Entity::initSprite(const std::string& filename)
{

    std::cout << filename << std::endl;
    if (texture_.loadFromFile(filename)) {
        sprite_.setTexture(texture_);
        sprite_.setScale(sf::Vector2f(3, 3));
    }
}

sf::Sprite Entity::GetSprite() { return sprite_; }

bool Entity::MoveLeft(float dt)
{
    xPos_ -= speed_ * dt;
    return true;
}

bool Entity::MoveRight(float dt)
{
    xPos_ += speed_ * dt;
    return true;
}

bool Entity::MoveDown(float dt)
{
    yPos_ += speed_ * dt;
    return true;
}

bool Entity::MoveUp(float dt)
{
    yPos_ -= speed_ * dt;
    return true;
}