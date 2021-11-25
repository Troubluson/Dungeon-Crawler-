#pragma once

#ifndef _ENTITY_CLASS_
#define _ENTITY_CLASS_
class Entity {
public:
    Entity(const std::string& spriteLocation, float xPos, float yPos, sf::Vector2f spriteDims);
    Entity(const std::string& spirteLocation, sf::Vector2f pos, sf::Vector2f spriteDims);
    Entity(sf::Sprite& sprite, float xPos, float yPos);
    Entity(sf::Sprite& sprite, sf::Vector2f pos);

    sf::Sprite& GetSprite() { return sprite_; };
    sf::Vector2f& GetPos() { return pos_; }
    sf::Vector2i GetPosI() { return sf::Vector2i(pos_); }
    sf::Vector2f GetSpritePosition() { return sprite_.getPosition(); } // might be unnecessary, because sprite pos should be same as that returned of GetPos()
    void setPos(sf::Vector2f newPos) { pos_ = newPos; } // might be unnecessary, because sprite pos should be same as that returned of GetPos()

    void Render(sf::RenderTarget* target);

protected:
    sf::Sprite sprite_;
    sf::Texture texture_;
    void initSprite(const std::string& spriteLocation, sf::Vector2f spriteDims);

    sf::Vector2f pos_;
};
#endif
