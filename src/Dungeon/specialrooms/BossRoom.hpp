#ifndef _BOSS_ROOM_
#define _BOSS_ROOM_

#include "Dungeon/roomInstance.hpp"

class BossRoom : public RoomInstance {
public:
    BossRoom(sf::Vector2u window_size, sf::Vector2i choords);
    BossRoom() { }
    ~BossRoom() { }
    virtual void setTiles(sf::Vector2u window_size);

private:
};

#endif