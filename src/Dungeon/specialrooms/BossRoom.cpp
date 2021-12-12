#include "BossRoom.hpp"
BossRoom::BossRoom(sf::Vector2u window_size, sf::Vector2i coords)
    : RoomInstance(window_size, coords)
{
    setTiles(window_size);
}

void BossRoom::Enter(PlayerPS player, Direction direction)
{
    visited_ = true;
    if (!cleared_) {
        MonsterSP monster;
        while (monsters_.empty()) {
            BossSpawner bossSpawner = BossSpawner();
            do {
                monster = bossSpawner.SpawnMonster(roomSize_, player);
            } while (monster == nullptr || !positionIsWalkable(monster->GetBaseBoxAt(monster->GetPos())));
            monster->SetTarget(player);
            monsters_.push_back(monster);
        }
    }
    player->SetPosAndOldPos(sf::Vector2f(GetEntranceInDirection(direction))); // prevents us from getting stuck in the wall
}

void BossRoom::setTiles(sf::Vector2u window_size)
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
                    row.push_back(new WallTile("content/sprites/walls/topwallLEFTSIDE.png", k, n));
                } else if (j == xTileCount - 1) {
                    row.push_back(new WallTile("content/sprites/walls/topwallRIGHTSIDE.png", k, n));
                } else {
                    row.push_back(new WallTile("content/sprites/walls/wallfront1.png", k, n));
                }
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

            } else if ((i == xTileCount / 3 && j == yTileCount / 2 - 1) || (i == xTileCount / 3 && j == yTileCount + 1) || (i == xTileCount / 3 && j == yTileCount / 2) || (i == xTileCount / 3 && j == yTileCount + 2)) {
                row.push_back(new WallTile("content/sprites/walls/wallfront1.png", k, n));

            } else if ((i == xTileCount / 3 - 1 && j == yTileCount / 2 - 1) || (i == xTileCount / 3 - 1 && j == yTileCount + 2) || (i == xTileCount / 3 - 1 && j == yTileCount / 2) || (i == xTileCount / 3 - 1 && j == yTileCount + 1)) {
                row.push_back(new WallTile("content/sprites/walls/wallfront1.png", k, n));

            } else {
                row.push_back(new FloorTile("content/sprites/floors/tile1.png", k, n));
            }
            k += 64;
        }
        n += 64;
        tileVector_.push_back(row);
    }
}