#pragma once
#ifndef _SPRITEHELPER_
#define _SPRITEHELPER_

class SpriteHelper {
private:
    /* data */
public:
    SpriteHelper(/* args */) {};
    sf::Sprite CreateSpriteFrom(const std::string& spriteFile, sf::Vector2f dimensions);
};

#endif
