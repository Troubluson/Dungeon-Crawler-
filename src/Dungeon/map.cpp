#include "map.hpp"
#include <time.h>

namespace {
int DIRECTION = 4;
}
Map::Map(sf::Vector2u size)
{
    srand(time(NULL));
    spawn_ = new StartingRoom(size);
    for (int i = 0; i < 5; i++) {
        rand() % 5;
        RoomInstance* newRoom = new RoomInstance(size);
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
