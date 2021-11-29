#include "roomTile.hpp"

RoomTile::RoomTile(std::string texture, float x, float y, bool walkable)
{
    if (!setTileTexture(texture)) {
        return;
    }

    position = sf::Vector2f(x, y);
    tileSprite.setPosition(position);
    walkable_ = walkable;
}

bool RoomTile::setTileTexture(std::string textureLocation)
{
    if (!tileTexture.loadFromFile(textureLocation)) {
        return false;
    }

    tileTexture.setSmooth(true);
    tileSprite.setTexture(tileTexture);
    tileSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    return true;
}

const sf::Vector2f RoomTile::getSize() const
{
    auto bounds = tileSprite.getLocalBounds();
    return sf::Vector2f(bounds.width, bounds.height);
}
const sf::Vector2f& RoomTile::getPosition() const
{
    return tileSprite.getPosition();
}
const sf::FloatRect RoomTile::getBoundingBox() const
{
    return tileSprite.getGlobalBounds();
}

const sf::Sprite& RoomTile::getSprite() const
{
    return tileSprite;
}

bool RoomTile::isWalkable() const
{
    return walkable_;
}
