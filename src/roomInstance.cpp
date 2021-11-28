#include "roomInstance.hpp"

RoomInstance::RoomInstance()
{
    gridLen_ = 20;
    setUpRoomInstance();
}

void RoomInstance::Render(sf::RenderTarget* target)
{
    target->draw(roomBackground);
}

void RoomInstance::setUpRoomInstance()
{
    exitPosition = sf::Vector2i(1, 0);
    playerPosition = sf::Vector2i(gridLen_ - 4, gridLen_ - 4);
    setTiles();
}

void RoomInstance::setTiles()
{
    tileVector_.clear();
    int n = 0;
    for (int i = 0; i < gridLen_; i++) {
        std::vector<RoomTile*> row;
        int k = 0;
        for (int j = 0; j < gridLen_; j++) {
            if (i == 0) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallleft.png", k, n, false, false));
                } else if (j == gridLen_ - 1) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomleft.png", k, n, false, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/toppartofwall1.png", k, n, false, false));
                }
            } else if (i == 1 && j != 0 && j != gridLen_ - 1) {
                row.push_back(new RoomTile("content/sprites/walls/wallfront1.png", k, n, false, false));
            } else if (i == 11) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallright.png", k, n, false, false));
                } else if (j == gridLen_ - 1) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomright.png", k, n, false, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottom.png", k, n, false, false));
                }
            } else if (i != 0 && j == 0) {
                row.push_back(new RoomTile("content/sprites/walls/topwallLEFTSIDE.png", k, n, false, false));
            } else if (i != 0 && j == gridLen_ - 1) {
                row.push_back(new RoomTile("content/sprites/walls/topwallRIGHTSIDE.png", k, n, false, false));
            } else {
                row.push_back(new RoomTile("content/sprites/floors/tile1.png", k, n, true, false));
            }

            k += 64;
        }
        n += 64;
        tileVector_.push_back(row);
    }
    renderSpriteBackground();
}

void RoomInstance::renderSpriteBackground()
{
    roomTexture.create(1280, 768);
    for (int i = 0; i < this->gridLen_; i++) {
        for (int j = 0; j < this->gridLen_; j++) {
            roomTexture.draw(this->tileVector_[i][j]->getSprite());
        }
    }
    roomTexture.display();
    roomBackground.setTexture(roomTexture.getTexture());
}

std::vector<RoomTile*> RoomInstance::getRoomTilesAt(sf::FloatRect entityBounds)
{
    // change this to calculate which tile from position
    std::vector<RoomTile*> tilesInBounds;
    for (auto tileRow : tileVector_) {
        for (auto tile : tileRow) {
            if (tile->getBoundingBox().intersects(entityBounds)) {
                tilesInBounds.push_back(tile);
            }
        }
    }
    return tilesInBounds;
}
// we end up needing to use the bounding box if we don't due to a character being in multiple tiles simultaneously
bool RoomInstance::positionIsWalkable(sf::FloatRect entityBounds)
{
    auto tilesInBounds = getRoomTilesAt(entityBounds);
    for (auto tile : tilesInBounds) {
        if (!tile->isWalkable()) {
            return false;
        }
    }
    return true;
}
std::vector<std::vector<RoomTile*>> RoomInstance::getTiles() const { return tileVector_; }
