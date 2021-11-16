#ifndef _ROOM_TILE_
#define _ROOM_TILE_

#include "PCH.hpp"

class RoomTile
{
public:
	sf::Vector2f position;
	sf::Texture tileTexture;
	sf::Sprite tileSprite;
	bool isWalkable;
	bool exitTile;

	RoomTile(std::string, float, float, bool, bool);
	bool setTileTexture(std::string);

private:
};

#endif