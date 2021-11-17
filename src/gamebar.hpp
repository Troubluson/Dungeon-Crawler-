#pragma once

#ifndef _GAMEBAR_CLASS_
#define _GAMEBAR_CLASS_

#include "player.hpp"

class Gamebar
{
public:
	Gamebar(Player player) {}

	void Render();

	void Update();

private:
	sf::RectangleShape background_;
	sf::RectangleShape playerBar_;
};
#endif