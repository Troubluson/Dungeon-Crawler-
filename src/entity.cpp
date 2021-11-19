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
    if (texture_.loadFromFile(filename)) {
        sprite_.setTexture(texture_);
        sprite_.setScale(sf::Vector2f(spriteSize, spriteSize));
    }
}

sf::Sprite Entity::GetSprite() { return sprite_; }

sf::Vector2f Entity::GetPos() { return sf::Vector2f(xPos_, yPos_); }
