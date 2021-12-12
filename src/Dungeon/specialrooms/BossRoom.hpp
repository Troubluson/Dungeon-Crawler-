#ifndef _BOSS_ROOM_
#define _BOSS_ROOM_

#include "Actors/Monsters/MonsterSpawner/BossSpawner.hpp"
#include "Dungeon/roomInstance.hpp"

class BossRoom : public RoomInstance {
public:
    BossRoom(sf::Vector2u window_size, sf::Vector2i coords);
    BossRoom() { }
    ~BossRoom() { }
    virtual void Enter(PlayerPS player, Direction direction);
    virtual void setTiles(sf::Vector2u window_size);

private:
};

#endif