#pragma once

#ifndef _ENTITY_CLASS_
#define _ENTITY_CLASS_
class Entity {
public:
    Entity(const std::string& filename, float xPos, float yPos, int spriteSize);
    sf::Sprite GetSprite();

    void Render(sf::RenderTarget* target);

    bool MoveLeft(float dt);
    bool MoveRight(float dt);
    bool MoveDown(float dt);
    bool MoveUp(float dt);

protected:
    sf::Sprite sprite_;
    sf::Texture texture_;
    void initSprite(const std::string& filename, int spriteSize);

    float xPos_;
    float yPos_;
    float speed_ = 200;
};
#endif