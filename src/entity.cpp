#include "entity.hpp"

Entity::Entity(const std::string& spriteFile, float xPos, float yPos, sf::Vector2f spriteDims)
{
    xPos_ = xPos;
    yPos_ = yPos;
    initSprite(spriteFile, spriteDims);
    sprite_.setPosition(xPos, yPos);
}

void Entity::Render(sf::RenderTarget* target) { target->draw(sprite_); }

void Entity::initSprite(const std::string& spriteFile, sf::Vector2f spriteDims)
{
    if (texture_.loadFromFile(spriteFile)) {
        sprite_.setTexture(texture_);
        sprite_.setScale(spriteDims);
    }
}
