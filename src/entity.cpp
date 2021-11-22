#include "entity.hpp"

Entity::Entity(const std::string& filename, float xPos, float yPos, int spriteSize)
{
    xPos_ = xPos;
    yPos_ = yPos;
    initSprite(filename, spriteSize);
    sprite_.setPosition(xPos, yPos);
}

void Entity::Render(sf::RenderTarget* target) { target->draw(sprite_); }

void Entity::initSprite(const std::string& filename, int spriteSize)
{
    std::cout << filename << std::endl;
    if (texture_.loadFromFile(filename)) {
        sprite_.setTexture(texture_);
        sprite_.setScale(sf::Vector2f(spriteSize, spriteSize));
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

bool Entity::Move(float dt, float x, float y)
{
    float xMovement = (x / (std::abs(x) + std::abs(y))) * speed_;
    float yMovement = (y / (std::abs(x) + std::abs(y))) * speed_;
    xMovement *= dt;
    yMovement *= dt;
    xPos_ += xMovement;
    yPos_ += yMovement;
    sprite_.setPosition(xPos_, yPos_);
    return true;
}