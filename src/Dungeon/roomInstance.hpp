
#include "roomTile.hpp"
#include <vector>

#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

class RoomInstance {
public:
    RoomInstance(sf::Vector2u window_size);

    void Render(sf::RenderTarget* target);
    void setUpRoomInstance(sf::Vector2u);
    void setTiles(sf::Vector2u);
    void renderSpriteBackground(sf::Vector2u);
    std::vector<RoomTile*> getRoomTilesAt(sf::FloatRect bounds);
    bool positionIsWalkable(sf::FloatRect bounds);
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