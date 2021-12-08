#ifndef _ROOM_TILE_
#define _ROOM_TILE_

#include "PCH.hpp"

class RoomTile {
public:
    RoomTile(std::string texture, float x, float y, bool walkable, bool penetratable);
    const sf::Vector2f getSize() const;
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getBoundingBox() const;
    const sf::Sprite& getSprite() const;
    bool isWalkable() const;
    bool isPenetratable() const;

private:
    sf::Vector2f position;
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    bool walkable_;
    bool penetratable_;

    bool setTileTexture(std::string);
};

class WallTile : public RoomTile {
public:
    WallTile(std::string texture, float x, float y)
        : RoomTile(texture, x, y, false, false)
    {
    }
};

class FrontWallTile : public RoomTile {
public:
    FrontWallTile(std::string texture, float x, float y)
        : RoomTile(texture, x, y, false, true)
    {
    }
};

class FloorTile : public RoomTile {
public:
    FloorTile(std::string texture, float x, float y)
        : RoomTile(texture, x, y, true, true)
    {
    }
};

#endif