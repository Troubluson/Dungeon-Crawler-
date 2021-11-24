#ifndef _MAP_
#define _MAP_
#include "PCH.hpp"
#include "roomInstance.hpp"

class Map {
private:
public:
    Map();
    ~Map() { }
    void loadRoom(sf::RenderTarget*);
    std::vector<RoomInstance*> dungeon;
};

#endif