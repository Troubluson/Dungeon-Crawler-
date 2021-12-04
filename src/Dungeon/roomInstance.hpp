
#include "roomTile.hpp"
#include <vector>

#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

enum class Direction {
    Up,
    Down,
    Left,
    Right,
    Count
};

class RoomInstance {
public:
    RoomInstance(sf::Vector2u window_size, sf::Vector2i choords);
    RoomInstance() { }
    void Render(sf::RenderTarget* target);
    void setUpRoomInstance(sf::Vector2u window_size);
    virtual void setTiles(sf::Vector2u window_size);
    void renderSpriteBackground(sf::Vector2u window_size);
    std::vector<RoomTile*> getRoomTilesAt(sf::FloatRect bounds);
    bool positionIsWalkable(sf::FloatRect bounds);
    std::vector<std::vector<RoomTile*>> getTiles() const;
    bool HasNeighBorInDir(Direction dir) const;
    void CreateExit(Direction dir);
    /**
     * @brief Connects two rooms to each other
     *
     * @param    dir                  Direction where the new room resides
     * @param    room                 The new room
     * \note Also adds the rooms as a connection on the argument room's side
     */
    void Connect(Direction dir, RoomInstance* room);
    RoomInstance* GetRoomInDir(Direction dir);
    sf::Vector2i GetChoords() { return choords_; }

protected:
    sf::Vector2u roomSize_;
    sf::Vector2i choords_;
    std::vector<std::vector<RoomTile*>> tileVector_;
    sf::RenderTexture roomTexture;
    sf::Sprite roomBackground;
    int gridLen_;
};

#endif