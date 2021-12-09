#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

#include "Actors/player.hpp"
class Gamebar {
public:
    Gamebar(Player* player);
    Gamebar() {};

    void Render(sf::RenderTarget* target);

    void Update();

private:
    Player* player_;
    sf::Font font_;
    sf::RectangleShape background_;
    sf::RectangleShape greenBar_;
    sf::RectangleShape redBar_;
    sf::RectangleShape violetBar_;
    sf::RectangleShape yellowBar_;
    sf::Text hp_;
};
#endif