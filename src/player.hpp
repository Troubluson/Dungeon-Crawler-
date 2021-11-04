#pragma once

#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

class Player
{
public:
	Player();
	virtual ~Player();

	void Update();

	void Render(sf::RenderTarget *target);

private:
	sf::RectangleShape shape_;

	void initVariables();

	void initShape();
};

#endif