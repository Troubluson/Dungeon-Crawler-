#pragma once
#ifndef _SPRITEHELPER_
#define _SPRITEHELPER_

namespace spritehelper {
void CreateSpriteFrom(const std::string& spriteFile, sf::Vector2f dimensions, sf::Sprite& sprite, sf::Texture& texture);

void SetScale(sf::Vector2f wantedDimension, sf::Sprite& sprite);

void RotateSprite(sf::Vector2f directionOfRotation, sf::Sprite& sprite);
void SetOriginBottomCenter(sf::Sprite& sprite);

} // namespace

#endif
