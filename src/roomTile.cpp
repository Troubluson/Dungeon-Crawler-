#include "roomTile.hpp"



RoomTile::RoomTile(std::string texture, float x, float y, bool walkable, bool exit)
{
	if (!setTileTexture(texture))
	{
		return;
	}

	position = sf::Vector2f(x,y);
	tileSprite.setPosition(position);
	isWalkable = walkable;
	exitTile = exit;

}

bool RoomTile::setTileTexture(std::string textureLocation)
{
	if (!tileTexture.loadFromFile(textureLocation))
	{
		return false;
	}

	tileTexture.setSmooth(true);
	tileSprite.setTexture(tileTexture);
	tileSprite.setTextureRect(sf::IntRect(0,0,64,64));
	return true;
}




