#pragma once
#ifndef _MAP_
#define _MAP_
#include "Actors/player.hpp"
#include "PCH.hpp"
#include "roomInstance.hpp"
#include "startingRoom.hpp"

class Map {

public:
    /**
     * @brief Initializes variables for new room and calls CreateDungeon()
     *
     * @param    sizeOfRooms           the size we want our rooms to be
     * @param    noRooms              The number of rooms we want the dungeon to consist of
     */
    Map(sf::Vector2u sizeOfRooms, int noRooms, Player& player);

    /**
     * @brief Renders the current room to the given target
     *
     */
    void RenderCurrentRoom(sf::RenderTarget* target);

    /**
     * @brief Create the actual dungeon
     *
     * @param    noRooms              number of rooms on in the dungeon
     * @return true dungeon creation succeeded
     * @return false dungeon creation failed
     */
    bool CreateDungeon(int noRooms);

    void MovePlayer(Direction dir);

    /**
     * @brief Get the Room in the argument direction
     *
     * @param    direction                 The direction
     * @return  returns room, or nullptr if not found
     */
    RoomInstance* GetRoomInDir(Direction direction);

    /**
     * @brief Converts a Direction to a unit vector and returns it
     *
     * @param    direction            the direction
     * @return sf::Vector2i the converted vector
     */
    sf::Vector2i DirToVec(Direction direction);

    /**
     * @brief Get the room the player is in on the map
     *
     * @return RoomInstance* The room
     */
    RoomInstance* GetCurrentRoom();

private:
    void Move(Direction dir);

    /**
     * @brief Get the room at the wanted choordinate on the map
     *
     * @param    choord               Desciption
     * @return RoomInstance*
     */
    RoomInstance* GetRoomAt(sf::Vector2i choord);

    std::pair<int, int> getKey();
    std::pair<int, int> getKey(sf::Vector2i choord);
    sf::Vector2u roomSize_;
    RoomInstance* spawn_;
    sf::Vector2i currentPos_;
    std::map<std::pair<int, int>, RoomInstance*> dungeon_; // cant use vector2i as a key
    Player& player_;
};

#endif