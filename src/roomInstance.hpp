#include "PCH.hpp"
#include "roomTile.hpp"
#include <vector>

#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

class RoomInstance {
public:
    RoomInstance() = default;
    RoomInstance(sf::Vector2u size);

    void Render(sf::RenderTarget* target);
    void setUpRoomInstance();
    void setTiles();
    void renderSpriteBackground();
    std::vector<RoomTile*> getRoomTilesAt(sf::FloatRect bounds);
    bool positionIsWalkable(sf::FloatRect bounds);
    std::vector<std::vector<RoomTile*>> getTiles() const;
    const sf::Vector2u getRoomSize() const;

private:
    sf::Vector2i exitPosition;
    sf::Vector2i playerPosition;

    std::vector<std::vector<RoomTile*>> tileVector_;
    int gridLen_;
    sf::Vector2u size_;
    sf::RenderTexture roomTexture;
    sf::Sprite roomBackground;
};

#endif