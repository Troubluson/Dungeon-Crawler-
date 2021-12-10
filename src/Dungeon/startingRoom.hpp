#pragma once
#ifndef _STARTING_ROOM_CLASS_
#define _STARTING_ROOM_CLASS_
#include "roomInstance.hpp"

class StartingRoom : public RoomInstance {
public:
    StartingRoom(sf::Vector2u window_size, sf::Vector2i choords);
    StartingRoom() { }
    ~StartingRoom() { }
    virtual void setTiles(sf::Vector2u window_size);

private:
};

#endif
