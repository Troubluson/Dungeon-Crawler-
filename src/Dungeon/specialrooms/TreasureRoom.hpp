#ifndef _TREASURE_ROOM_
#define _TREASURE_ROOM_

#include "Dungeon/roomInstance.hpp"

class TreasureRoom : public RoomInstance {
public:
    TreasureRoom(sf::Vector2u window_size, sf::Vector2i choords);
    TreasureRoom() { }
    ~TreasureRoom() { }
    virtual void setTiles(sf::Vector2u window_size);

private:
};

#endif