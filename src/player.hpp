#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "character.hpp"
#include "gamebar.hpp"

class Player : public Character {
public:
    Player();

    int Attack(Character ch);

    virtual void Render(sf::RenderTarget* target);

private:
    Gamebar gamebar_;
};

#endif