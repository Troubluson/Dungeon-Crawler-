#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

#include "Actors/player.hpp"
#include "Combat/Health/HealthPotions.hpp"
#include "Combat/Health/Potion.hpp"
#include "Utility/SpriteHelper.hpp"
class Gamebar {
public:
    Gamebar(Player* player);
    Gamebar() {};

    void Render(sf::RenderTarget* target);

    void Update();

    void RenderInventory(sf::RenderTarget* target);

private:
    Player* player_;
    sf::Font font_;
    sf::RectangleShape background_;
    sf::RectangleShape greenBar_;
    sf::RectangleShape redBar_;
    sf::RectangleShape violetBar_;
    sf::RectangleShape yellowBar_;
    sf::Text hp_;

    sf::Vector2f redpos_ = sf::Vector2f(800, 5);
    sf::Vector2f greenpos_ = sf::Vector2f(900, 5);
    sf::Vector2f yellowpos_ = sf::Vector2f(1000, 5);
    sf::Vector2f violetpos_ = sf::Vector2f(1100, 5);

    sf::Sprite redsprite_;
    sf::Texture redtexture_;

    sf::Sprite greensprite_;
    sf::Texture greentexture_;

    sf::Sprite yellowsprite_;
    sf::Texture yellowtexture_;

    sf::Sprite violetsprite_;
    sf::Texture violettexture_;
};
#endif