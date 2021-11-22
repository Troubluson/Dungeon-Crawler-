#include "SpriteHelper.hpp"

void SpriteHelper::CreateSpriteFrom(const std::string& spriteFile, sf::Vector2f dimensions, sf::Sprite& sprite, sf::Texture& texture)
{
    if (texture.loadFromFile(spriteFile)) {
        sprite.setTexture(texture);
        sprite.setScale(dimensions);
    }
}