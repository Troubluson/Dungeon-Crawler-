#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

#include "Actors/player.hpp"
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

private:
    PlayerPS player_;
    sf::Font font_;
    sf::RectangleShape background_;
    sf::RectangleShape greenBar_;
    sf::RectangleShape redBar_;
    sf::RectangleShape violetBar_;
    sf::RectangleShape yellowBar_;
    sf::Text hp_;
};
#endif