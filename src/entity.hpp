#pragma once

#ifndef _ENTITY_CLASS_
#define _ENTITY_CLASS_
class Entity {
public:
    Entity(const std::string& filename, float xPos, float yPos, int spriteSize);

    sf::Sprite GetSprite();
    sf::Vector2f GetPos();

    void Render(sf::RenderTarget* target);

protected:
    sf::Sprite sprite_;
    sf::Texture texture_;
    void initSprite(const std::string& filename, int spriteSize);

    float xPos_;
    float yPos_;
};
#endif