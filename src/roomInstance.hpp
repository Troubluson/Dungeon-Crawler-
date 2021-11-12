#include "PCH.hpp"
#include "roomTile.hpp"
#include <vector>


#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_



class RoomInstance{
public:
	RoomInstance();
	std::vector<std::vector<RoomTile*>> tile_;
	int gridLen_;
	void Render(sf::RenderTarget *target);
	void setUpRoomInstance();
	void setTiles();

private:
	sf::Vector2i exitPosition;
	sf::Vector2i playerPosition;
};

#endif