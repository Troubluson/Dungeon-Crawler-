#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

#include "Actors/player.hpp"
#include "Combat/Health/HealthPotions.hpp"
#include "Combat/Health/Potion.hpp"
#include "Utility/SpriteHelper.hpp"
class Gamebar {
public:
    /**
     * @brief Construct a new Gamebar object, meaning creates the gamebars for player health, attack cooldown and dash cooldown
     *
     * @param    player              player which is tracked
     */
    Gamebar(PlayerPS player);

    Gamebar() {};
    /**
     * @brief renders the gamebars
     *
     * @param    target               window here gamebars should be drawn
     */
    void Render(sf::RenderTarget* target);
    /**
     * @brief keeps the gamebars updates when damage is lost and when attack and dash is used
     *
     */
    void Update();

    void RenderInventory(sf::RenderTarget* target);

private:
    PlayerPS player_;
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