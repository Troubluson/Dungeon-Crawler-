#ifndef _ROOM_TILE_
#define _ROOM_TILE_

#include "PCH.hpp"

class RoomTile {
public:
    RoomTile(std::string texture, float x, float y, bool walkable, bool penetratable = false);
    const sf::Vector2f getSize() const;
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getBoundingBox() const;
    const sf::Sprite& getSprite() const;
    bool isWalkable() const;

private:
    sf::Vector2f position;
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    bool walkable_;
    bool penetratable_;

    bool setTileTexture(std::string);
};

#endif