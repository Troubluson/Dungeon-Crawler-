#include "map.hpp"

Map::Map(sf::Vector2u size)
{
    spawn_ = new StartingRoom(size);
    for (int i = 0; i < 5; i++) {
        dungeon_.push_back(new RoomInstance(size));
    }
    room = 0;
}

void Map::loadRoom(sf::RenderTarget* window)
{
    dungeon_[room]->Render(window);
}

void Map::nextRoom()
{
    if (room < 4) {
        room += 1;
    }
}

RoomInstance* Map::GetRoom()
{
    return dungeon_[room];
}
