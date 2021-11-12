#include "roomInstance.hpp"



RoomInstance::RoomInstance()
{
	gridLen_ = 20;
	setUpRoomInstance();

}

void RoomInstance::Render(sf::RenderTarget *target)
{
	target->draw(roomBackground);
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
			if (i==0)
			{
				if (j==0)
				{
					row.push_back(new RoomTile("content/sprites/topwallleft.png",k, n, true, false));
				}
				else if(j==19)
				{
					row.push_back(new RoomTile("content/sprites/topwallbottomleft.png",k, n, true, false));
				}
				else
				{
					row.push_back(new RoomTile("content/sprites/toppartofwall1.png",k, n, true, false));
				}
			}
			else if (i==1 && j!=0 && j!=19)
			{
				row.push_back(new RoomTile("content/sprites/wallfront1.png",k, n, true, false));
			}
			else if (i==11)
			{
				if (j==0)
				{
					row.push_back(new RoomTile("content/sprites/topwallright.png",k, n, true, false));
				}
				else if(j==19)
				{
					row.push_back(new RoomTile("content/sprites/topwallbottomright.png",k, n, true, false));
				}
				else
				{
					row.push_back(new RoomTile("content/sprites/topwallbottom.png",k, n, true, false));
				}

			}
			else if (i!=0 && j==0)
			{
				row.push_back(new RoomTile("content/sprites/topwallLEFTSIDE.png",k, n, true, false));
			}
			else if (i!=0 && j==19)
			{
				row.push_back(new RoomTile("content/sprites/topwallRIGHTSIDE.png",k, n, true, false));
			}
			else
			{
				row.push_back(new RoomTile("content/sprites/tile1.png",k, n, true, false));
			}

			k += 64;
		}
		n+=64;
		tile_.push_back(row);


	}
	renderSpriteBackground();

}

void RoomInstance::renderSpriteBackground()
{
	roomTexture.create(1280, 768);
	for(int i = 0; i < this->gridLen_; i++)
	{
		for (int j = 0; j < this->gridLen_; j++)
		{
			roomTexture.draw(this->tile_[i][j]->tileSprite);
		}
	}
	roomTexture.display();
	roomBackground.setTexture(roomTexture.getTexture());
}


