#pragma once
#ifndef _MAP_
#define _MAP_
#include "PCH.hpp"
#include "roomInstance.hpp"
#include "startingRoom.hpp"

class Map {

public:
    Map(sf::Vector2u sizeOfRoom, uint noRooms);
    Map() { }
    void loadRoom(sf::RenderTarget*);
    void nextRoom();
    void CreateDungeon(uint noRooms);
    RoomInstance* GetRoom();
    RoomInstance* GetRoomAt(sf::Vector2i choord);

    void Move(Direction dir);
    /**
     * @brief Get the Room in the argument direction
     *
     * @param    direction                 The direction
     * @return  returns room, or nullptr if not found
     */
    RoomInstance* GetRoomInDir(Direction direction);
    sf::Vector2i DirToVec(Direction direction);
    RoomInstance* GetCurrentRoom();

private:
    std::pair<int, int> getKey();
    std::pair<int, int> getKey(sf::Vector2i choord);
    sf::Vector2u roomSize_;
    int room;
    RoomInstance* spawn_;
    sf::Vector2i currentPos_;
    std::map<std::pair<int, int>, RoomInstance*> dungeon_; // cant use vector2i as a key because its dumb
};

#endif