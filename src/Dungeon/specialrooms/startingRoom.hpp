#pragma once
#ifndef _STARTING_ROOM_CLASS_
#define _STARTING_ROOM_CLASS_
#include "Dungeon/roomInstance.hpp"

class StartingRoom : public RoomInstance {
public:
    /**
     * @brief Construct a new Starting Room object from window size and set its choordinates
     *
     * @param    window_size          size of window
     * @param    choords              choordinates of the starting room in map
     */
    StartingRoom(sf::Vector2u window_size, sf::Vector2i choords);
    StartingRoom() { }
    ~StartingRoom() { }
    virtual void setTiles(sf::Vector2u window_size);

private:
};

#endif
