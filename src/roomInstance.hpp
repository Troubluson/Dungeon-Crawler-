#include "PCH.hpp"
#include "roomTile.hpp"
#include <vector>

#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

class RoomInstance {
public:
    RoomInstance();
    std::vector<std::vector<RoomTile*>> tile_;
    int gridLen_;
    sf::RenderTexture roomTexture;
    sf::Sprite roomBackground;
    void Render(sf::RenderTarget* target);
    void setUpRoomInstance();
    void setTiles();
    void renderSpriteBackground();

private:
    sf::Vector2i exitPosition;
    sf::Vector2i playerPosition;
};

#endif