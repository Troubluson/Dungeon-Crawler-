#include "roomInstance.hpp"
#include <time.h>
namespace {
int TILE_AMOUNT = 7;
int NORMALTILE_EXTRA_WEIGHT = 4;
}

RoomInstance::RoomInstance(sf::Vector2u window_size, sf::Vector2i choords)
    : roomSize_(window_size)
    , choords_(choords)
{
    srand(time(NULL));

    setUpRoomInstance(window_size);
}

void RoomInstance::Render(sf::RenderTarget* target)
{
    target->draw(roomBackground);
}

void RoomInstance::setUpRoomInstance(sf::Vector2u window_size)
{
    setTiles(window_size);
}

void RoomInstance::setTiles(sf::Vector2u window_size)
{
    tileVector_.clear();
    int xTileCount = window_size.x / 64;
    int yTileCount = window_size.y / 64;
    int n = 0;
    for (int i = 0; i < yTileCount; ++i) {
        std::vector<RoomTile*> row;
        int k = 0;
        for (int j = 0; j < xTileCount; ++j) {
            if (i == 0) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallleft.png", k, n, false, false));
                } else if (j == xTileCount - 1) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomleft.png", k, n, false, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/toppartofwall1.png", k, n, false, false));
                }
            } else if (i == 1 && j != 0 && j != xTileCount - 1) {
                row.push_back(new RoomTile("content/sprites/walls/wallfront1.png", k, n, false, true));
            } else if (i == yTileCount - 1) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallright.png", k, n, false, false));
                } else if (j == xTileCount - 1) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomright.png", k, n, false, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottom.png", k, n, false, false));
                }
            } else if (i != 0 && j == 0) {
                row.push_back(new RoomTile("content/sprites/walls/topwallLEFTSIDE.png", k, n, false, false));
            } else if (i != 0 && j == xTileCount - 1) {
                row.push_back(new RoomTile("content/sprites/walls/topwallRIGHTSIDE.png", k, n, false, false));

            } else {
                int tileNumber = rand() % ((TILE_AMOUNT + 1) + NORMALTILE_EXTRA_WEIGHT) + 1;
                if (tileNumber > TILE_AMOUNT) {
                    tileNumber = 1;
                }
                std::string tilelocation = "content/sprites/floors/tile" + std::to_string(tileNumber) + ".png";
                row.push_back(new RoomTile(tilelocation, k, n, true, true));
            }

            k += 64;
        }
        n += 64;
        tileVector_.push_back(row);
    }
}

void RoomInstance::renderSpriteBackground(sf::Vector2u window_size)
{
    roomTexture.create(window_size.x, window_size.y);

    for (auto i = 0u; i < window_size.y / 64; i++) {
        for (auto j = 0u; j < window_size.x / 64; j++) {
            roomTexture.draw(this->tileVector_[i][j]->getSprite());
        }
    }
    roomTexture.display();
    roomBackground.setTexture(roomTexture.getTexture());
}


std::vector<std::vector<RoomTile*>> RoomInstance::getTiles() const
{
    return tileVector_;
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
// we end up needing to use the bounding box character being in multiple tiles simultaneously
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

void RoomInstance::CreateExit(Direction dir)
{
    // v<row, col>
    std::vector<std::pair<int, int>> tilesToReplace;
    auto firstRow = tileVector_[0];
    auto secondRow = tileVector_[1];
    switch (dir) {
    case Direction::Up: {
        for (auto i = 0u; i < 2; ++i) {
            tilesToReplace.push_back(std::make_pair(0, i + firstRow.size() / 2 - 1));
            tilesToReplace.push_back(std::make_pair(1, i + secondRow.size() / 2 - 1));
        }
        break;
    }
    case Direction::Down: {
        auto vSize = tileVector_.size() - 1;
        auto lastRow = tileVector_[vSize];
        for (auto i = 0u; i < 2; ++i) {
            tilesToReplace.push_back(std::make_pair(vSize, i + lastRow.size() / 2 - 1));
        }
        break;
    }
    case Direction::Left: {
        auto vSize = tileVector_.size() - 1;
        auto midCol1 = tileVector_[vSize / 2];
        auto midCol2 = tileVector_[vSize / 2 + 1];
        tilesToReplace.push_back(std::make_pair(vSize / 2, 0));
        tilesToReplace.push_back(std::make_pair(vSize / 2 + 1, 0));

        break;
    }
    case Direction::Right: {
        auto vSize = tileVector_.size() - 1;
        auto midRow1 = tileVector_[vSize / 2];
        auto midRow2 = tileVector_[vSize / 2 + 1];
        tilesToReplace.push_back(std::make_pair(vSize / 2, midRow1.size() - 1));
        tilesToReplace.push_back(std::make_pair(vSize / 2 + 1, midRow2.size() - 1));
        break;
    }
    default:
        break;
    } // switch
    for (auto tile : tilesToReplace) {
        auto pos = tileVector_[tile.first][tile.second]->getPosition();
        // delete tileVector_[tile.first][tile.second];
        tileVector_[tile.first][tile.second] = new RoomTile("content/sprites/floors/tile1.png", pos.x, pos.y, true, true);
    }
}
