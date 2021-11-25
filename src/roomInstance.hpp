#include "PCH.hpp"
#include "roomTile.hpp"
#include <vector>

#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

class RoomInstance {
public:
    RoomInstance();

    void Render(sf::RenderTarget* target);
    void setUpRoomInstance();
    void setTiles();
    void renderSpriteBackground();
    RoomTile* getRoomTileAt(sf::Vector2f position);
    bool positionIsWalkable(sf::Vector2f position);
    std::vector<std::vector<RoomTile*>> getTiles() const;

private:
    sf::Vector2i exitPosition;
    sf::Vector2i playerPosition;

    std::vector<std::vector<RoomTile*>> tileVector_;
    int gridLen_;
    sf::RenderTexture roomTexture;
    sf::Sprite roomBackground;
};

#endif