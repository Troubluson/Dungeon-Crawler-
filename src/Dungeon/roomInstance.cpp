#include "roomInstance.hpp"
#include <time.h>
namespace {
int TILE_AMOUNT = 7;
int NORMALTILE_EXTRA_WEIGHT = 4;
}

RoomInstance::RoomInstance(sf::Vector2u window_size, sf::Vector2i choords)
    : roomSize_(window_size)
    , choords_(choords)
    , spawner_(0)
{
    setTiles();
}

RoomInstance::~RoomInstance()
{
    for (auto m : monsters_) {
        delete m;
    }
}

void RoomInstance::Render(sf::RenderTarget* target)
{
    target->draw(roomBackground);
}

void RoomInstance::setTiles()
{
    tileVector_.clear();
    int xTileCount = roomSize_.x / 64;
    int yTileCount = roomSize_.y / 64;
    int n = 0;
    for (int i = 0; i < yTileCount; ++i) {
        std::vector<RoomTile*> row;
        int k = 0;
        for (int j = 0; j < xTileCount; ++j) {
            if (i == 0) {
                if (j == 0) {
                    row.push_back(new WallTile("content/sprites/walls/topwallleft.png", k, n));
                } else if (j == xTileCount - 1) {
                    row.push_back(new WallTile("content/sprites/walls/topwallbottomleft.png", k, n));
                } else {
                    row.push_back(new WallTile("content/sprites/walls/toppartofwall1.png", k, n));
                }
            } else if (i == 1 && j != 0 && j != xTileCount - 1) {
                row.push_back(new FrontWallTile("content/sprites/walls/wallfront1.png", k, n));
            } else if (i == yTileCount - 1) {
                if (j == 0) {
                    row.push_back(new WallTile("content/sprites/walls/topwallright.png", k, n));
                } else if (j == xTileCount - 1) {
                    row.push_back(new WallTile("content/sprites/walls/topwallbottomright.png", k, n));
                } else {
                    row.push_back(new WallTile("content/sprites/walls/topwallbottom.png", k, n));
                }
            } else if (i != 0 && j == 0) {
                row.push_back(new WallTile("content/sprites/walls/topwallLEFTSIDE.png", k, n));
            } else if (i != 0 && j == xTileCount - 1) {
                row.push_back(new WallTile("content/sprites/walls/topwallRIGHTSIDE.png", k, n));
            } else {
                int tileNumber = rand() % ((TILE_AMOUNT + 1) + NORMALTILE_EXTRA_WEIGHT) + 1;
                if (tileNumber > TILE_AMOUNT) {
                    tileNumber = 1;
                }
                std::string tilelocation = "content/sprites/floors/tile" + std::to_string(tileNumber) + ".png";
                row.push_back(new FloorTile(tilelocation, k, n));
            }

            k += 64;
        }
        n += 64;
        tileVector_.push_back(row);
    }
}

void RoomInstance::renderSpriteBackground()
{
    roomTexture.create(roomSize_.x, roomSize_.y);

    for (auto i = 0u; i < roomSize_.y / 64; ++i) {
        for (auto j = 0u; j < roomSize_.x / 64; ++j) {
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

bool RoomInstance::positionIsPenetratable(sf::FloatRect entityBounds)
{
    auto tilesInBounds = getRoomTilesAt(entityBounds);
    for (auto tile : tilesInBounds) {
        if (!tile->isPenetratable()) {
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
        tileVector_[tile.first][tile.second] = new FloorTile("content/sprites/floors/tile1.png", pos.x, pos.y);
    }
}

void RoomInstance::Enter(Player& player)
{

    if (!cleared_) {
        spawner_.SetMonsterAmount(5); // set according to player lvl somehow
        while (monsters_.size() < spawner_.GetMonsterAmount()) {
            Monster* monster;
            do {
                monster = spawner_.SpawnMonster(roomSize_, player);
            } while (monster == nullptr || !positionIsWalkable(monster->GetBaseBoxAt(monster->GetPos())));
            monster->SetTarget(player);
            monsters_.push_back(monster);
        }
    }
}

void RoomInstance::Exit()
{
    visited_ = true;
    if (monsters_.empty()) {
        cleared_ = true;
    }
}

std::vector<Monster*>& RoomInstance::GetMonsters()
{
    return monsters_;
}