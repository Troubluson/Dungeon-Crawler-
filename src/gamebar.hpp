#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

#include "Actors/player.hpp"
class Gamebar {
public:
    Gamebar(PlayerPS player);
    Gamebar() {};

    void Render(sf::RenderTarget* target);

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