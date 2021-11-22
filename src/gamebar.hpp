#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

class Gamebar {
public:
    Gamebar(int hitpoints);

    void Render(sf::RenderTarget* target);

    void Update();

private:
    int hitpoints_;
    sf::RectangleShape background_;
    sf::RectangleShape playerBar_;
};
#endif