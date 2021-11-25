#include "map.hpp"

Map::Map(sf::Vector2u size)
{
    for (int i = 0; i < 3; i++) {
        dungeon_.push_back(new RoomInstance(size));
    }
}

void Map::loadRoom(sf::RenderTarget* window)
{

    dungeon_[0]->Render(window);
}

RoomInstance* Map::GetRoom()
{
    return dungeon_[0];
}
