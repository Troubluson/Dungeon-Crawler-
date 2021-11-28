#include "entity.hpp"

Entity::Entity(const std::string& spriteFile, float xPos, float yPos, sf::Vector2f spriteDims)
    : pos_(sf::Vector2f(xPos, yPos))
{
    initSprite(spriteFile, spriteDims);
    sprite_.setPosition(xPos, yPos);
}
Entity::Entity(const std::string& spriteFile, sf::Vector2f pos, sf::Vector2f spriteDims)
    : pos_(pos)
{
    initSprite(spriteFile, spriteDims);
    sprite_.setPosition(pos);
}

Entity::Entity(sf::Sprite& sprite, float xPos, float yPos)
    : sprite_(sprite)
    , pos_(sf::Vector2f(xPos, yPos))
{
}

Entity::Entity(sf::Sprite& sprite, sf::Vector2f pos)
    : sprite_(sprite)
    , pos_(pos)
{
}

void Entity::Render(sf::RenderTarget* target) { target->draw(sprite_); }

void Entity::initSprite(const std::string& spriteFile, sf::Vector2f spriteDims)
{
    if (texture_.loadFromFile(spriteFile)) {
        sprite_.setTexture(texture_);
        sprite_.setScale(spriteDims);
    }
}
