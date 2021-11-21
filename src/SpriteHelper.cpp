#include "SpriteHelper.hpp"

sf::Sprite SpriteHelper::CreateSpriteFrom(const std::string& spriteFile, sf::Vector2f dimensions)
{
    sf::Texture texture;
    sf::Sprite sprite;
    if (texture.loadFromFile(spriteFile)) {
        sprite.setTexture(texture);
        sprite.setScale(dimensions);
    }
    return sprite;
}