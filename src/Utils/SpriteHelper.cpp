#include "Utils/SpriteHelper.hpp"
#define PI 3.14159265

namespace sprite {
void CreateSpriteFrom(const std::string& spriteFile, sf::Vector2f dimensions, sf::Sprite& sprite, sf::Texture& texture)
{
    if (texture.loadFromFile(spriteFile)) {
        sprite.setTexture(texture);
        sprite.setScale(dimensions);
    }
}

void SetScale(sf::Vector2f wantedDimension, sf::Sprite& sprite)
{
    auto bounds = sprite.getLocalBounds();
    auto scaleX = wantedDimension.x / bounds.width;
    auto scaleY = wantedDimension.y / bounds.height;
    sprite.setScale(scaleX, scaleY);
    sprite.setOrigin(bounds.width / 2, bounds.height);
}

void RotateSprite(sf::Vector2f directionOfRotation, sf::Sprite& sprite)
{
    auto angle = atan2(directionOfRotation.y, directionOfRotation.x) * 180 / PI + 90;
    sprite.setRotation(angle);
}
} // namespace
