#include "roomInstance.hpp"



RoomInstance::RoomInstance()
{
	gridLen_ = 8;
	setUpRoomInstance();
}

void RoomInstance::Render(sf::RenderTarget *target)
{
	for(int i = 0; i < this->gridLen_; i++)
	{
		for (int j = 0; j < this->gridLen_; j++)
		{
			target->draw(this->tile_[i][j]->tileSprite);
		}
	}
}

void RoomInstance::setUpRoomInstance()
{
	exitPosition = sf::Vector2i(1,0);
	playerPosition = sf::Vector2i(gridLen_- 4, gridLen_- 4);
	setTiles();
}

void RoomInstance::setTiles()
{
	tile_.clear();
	int n = 0;
	for (int i = 0; i<gridLen_ ; i++){
		std::vector<RoomTile *> row;
		int k = 0;
		for (int j = 0; j<gridLen_ ; j++){
			row.push_back(new RoomTile("content/sprites/tile1.png",k, n, true, false));
			k += 50;
		}
		n+=50;
		tile_.push_back(row);
	}

}


