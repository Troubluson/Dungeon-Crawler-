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
	std::vector<RoomTile *> firstRow;
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",0, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",50, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",100, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",150, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",200, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",250, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",300, 0, true, false));
	firstRow.push_back(new RoomTile("content/sprites/tile1.png",350, 0, true, false));
	tile_.push_back(firstRow);
	std::vector<RoomTile *> secondRow;
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",0, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",50, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",100, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",150, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",200, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",250, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",300, 50, true, false));
	secondRow.push_back(new RoomTile("content/sprites/tile1.png",350, 50, true, false));
	tile_.push_back(secondRow);
	std::vector<RoomTile *> thirdRow;
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",0, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",50, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",100, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",150, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",200, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",250, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",300, 100, true, false));
	thirdRow.push_back(new RoomTile("content/sprites/tile1.png",350, 100, true, false));
	tile_.push_back(thirdRow);
	std::vector<RoomTile *> fourthRow;
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",0, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",50, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",100, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",150, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",200, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",250, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",300, 150, true, false));
	fourthRow.push_back(new RoomTile("content/sprites/tile1.png",350, 150, true, false));
	tile_.push_back(fourthRow);
	std::vector<RoomTile *> fifthRow;
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",0, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",50, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",100, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",150, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",200, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",250, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",300, 200, true, false));
	fifthRow.push_back(new RoomTile("content/sprites/tile1.png",350, 200, true, false));
	tile_.push_back(fifthRow);
	std::vector<RoomTile *> sixthRow;
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",0, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",50, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",100, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",150, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",200, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",250, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",300, 250, true, false));
	sixthRow.push_back(new RoomTile("content/sprites/tile1.png",350, 250, true, false));
	tile_.push_back(sixthRow);
	std::vector<RoomTile *> seventhRow;
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",0, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",50, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",100, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",150, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",200, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",250, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",300, 300, true, false));
	seventhRow.push_back(new RoomTile("content/sprites/tile1.png",350, 300, true, false));
	tile_.push_back(seventhRow);
	std::vector<RoomTile *> eigthRow;
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",0, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",50, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",100, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",150, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",200, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",250, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",300, 350, true, false));
	eigthRow.push_back(new RoomTile("content/sprites/tile1.png",350, 350, true, false));
	tile_.push_back(eigthRow);

}


