#pragma once

#ifndef _ENTITY_CLASS_
#define _ENTITY_CLASS_
class Entity {
public:
    Entity(const std::string& spriteLocation, float xPos, float yPos, sf::Vector2f spriteDims);
    Entity(sf::Sprite& sprite, float xPos, float yPos);

    sf::Sprite GetSprite() { return sprite_; };
    sf::Vector2f GetPos() { return sf::Vector2f(xPos_, yPos_); }
    sf::Vector2i GetPosI() { return sf::Vector2i(xPos_, yPos_); }

    sf::Vector2f GetSpritePosition() { return sprite_.getPosition(); } // might be unnecessary, because sprite pos should be same as that returned of GetPos()

    void Render(sf::RenderTarget* target);

protected:
    sf::Sprite sprite_;
    sf::Texture texture_;
    void initSprite(const std::string& spriteLocation, sf::Vector2f spriteDims);

    float xPos_;
    float yPos_;
};
#endif