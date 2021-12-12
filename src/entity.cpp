#include "entity.hpp"

Entity::Entity(const std::string& spriteFile, float xPos, float yPos, sf::Vector2f spriteDims)
    : pos_(sf::Vector2f(xPos, yPos))
    , oldPos_(pos_)
    , texture_(sf::Texture())
{
    initSprite(spriteFile, spriteDims);
    sprite_.setPosition(xPos, yPos);
}

Entity::Entity(const std::string& spriteFile, sf::Vector2f pos, sf::Vector2f spriteDims)
    : Entity(spriteFile, pos.x, pos.y, spriteDims)
{
}

Entity::Entity(sf::Sprite& sprite, float xPos, float yPos)
    : pos_(sf::Vector2f(xPos, yPos))
    , oldPos_(pos_)
    , sprite_(sprite)
    , texture_(sf::Texture())
{
}

Entity::Entity(sf::Sprite& sprite, sf::Vector2f pos)
    : Entity(sprite, pos.x, pos.y)
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

sf::FloatRect Entity::GetBaseBoxAt(sf::Vector2f pos) const
{
    auto spriteBounds = sprite_.getGlobalBounds();
    // set to use new position
    spriteBounds.left = pos.x;
    spriteBounds.top = pos.y;
    // use only lower half
    spriteBounds.height *= 1.0f / 2;
    spriteBounds.top += spriteBounds.height;
    return spriteBounds;
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

void Entity::SetPos(sf::Vector2f pos)
{
    pos_ = pos;
    sprite_.setPosition(pos_);
}

void Entity::SetPosAndOldPos(sf::Vector2f pos)
{
    SetPos(pos);
    oldPos_ = pos;
}
