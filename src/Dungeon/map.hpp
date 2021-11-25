#pragma once
#ifndef _MAP_
#define _MAP_
#include "PCH.hpp"
#include "roomInstance.hpp"

class Map {
private:
public:
    Map(sf::Vector2u size);
    Map() { }
    ~Map() { }
    void loadRoom(sf::RenderTarget*);
    RoomInstance* GetRoom();
    std::vector<RoomInstance*> dungeon_;
};

#endif