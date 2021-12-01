#include "map.hpp"

Map::Map(sf::Vector2u size)
{
    spawn_ = new StartingRoom(size);
    for (int i = 0; i < 5; i++) {
        dungeon_.push_back(new RoomInstance(size));
    }
    room = -1;
}

void Map::loadRoom(sf::RenderTarget* window)
{
    if (room >= 0) {
        dungeon_[room]->Render(window);
    } else {
        spawn_->Render(window);
    }
}

void Map::nextRoom()
{
    if (room < 4) {
        room += 1;
    }
}

RoomInstance* Map::GetRoom()
{
    if (room >= 0) {
        return dungeon_[room];
    } else {
        return spawn_;
    }
}
