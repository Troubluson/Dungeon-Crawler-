#include "map.hpp"

Map::Map()
{
    for (int i = 0; i < 3; i++) {
        dungeon.push_back(new RoomInstance());
    }
}

void Map::loadRoom(sf::RenderTarget* window)
{

    dungeon[0]->Render(window);
}
