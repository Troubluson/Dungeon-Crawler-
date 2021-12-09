#include "entity.hpp"

Entity::Entity(const std::string& spriteFile, float xPos, float yPos, sf::Vector2f spriteDims)
    : pos_(sf::Vector2f(xPos, yPos))
    , oldPos_(pos_)
{
    initSprite(spriteFile, spriteDims);
    sprite_.setPosition(xPos, yPos);
}
Entity::Entity(const std::string& spriteFile, sf::Vector2f pos, sf::Vector2f spriteDims)
    : pos_(pos)
    , oldPos_(pos_)

{
    initSprite(spriteFile, spriteDims);
    sprite_.setPosition(pos);
}

Entity::Entity(sf::Sprite& sprite, float xPos, float yPos)
    : sprite_(sprite)
    , pos_(sf::Vector2f(xPos, yPos))
    , oldPos_(pos_)

{
}

Entity::Entity(sf::Sprite& sprite, sf::Vector2f pos)
    : sprite_(sprite)
    , pos_(pos)
    , oldPos_(pos_)
{
}

const sf::Vector2f& Entity::GetOldPosition() const
{
    return oldPos_;
}

sf::FloatRect Entity::GetSpriteBounds() const
{
    return sprite_.getGlobalBounds();
}

sf::Vector2f Entity::GetSpriteCenter() const
{
    auto spriteOrigin = GetSpritePosition();
    auto localSpriteBounds = sprite_.getGlobalBounds();
    spriteOrigin.x += 1.0f / 2 * localSpriteBounds.width;
    spriteOrigin.y += 1.0f / 2 * localSpriteBounds.height;
    return spriteOrigin;
}

void Entity::Render(sf::RenderTarget* target) { target->draw(sprite_); }

void Entity::initSprite(const std::string& spriteFile, sf::Vector2f spriteDims)
{
    if (texture_.loadFromFile(spriteFile)) {
        sprite_.setTexture(texture_);
        sprite_.setScale(spriteDims);
    }
}
void Entity::SetPosAndOldPos(sf::Vector2f pos)
{
    pos_ = pos;
    oldPos_ = pos;
}
