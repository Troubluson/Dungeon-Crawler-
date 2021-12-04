#include "startingRoom.hpp"

StartingRoom::StartingRoom(sf::Vector2u window_size, sf::Vector2i choords)
    : RoomInstance(window_size, choords)
{
    setTiles(window_size);
}

void StartingRoom::setTiles(sf::Vector2u window_size)
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
                    row.push_back(new RoomTile("content/sprites/walls/topwallleft.png", k, n, false));
                } else if (j == xTileCount - 1) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomleft.png", k, n, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/toppartofwall1.png", k, n, false));
                }
            } else if (i == 1 && j != 0 && j != xTileCount - 1) {
                row.push_back(new RoomTile("content/sprites/walls/wallfront1.png", k, n, false, true));
            } else if (i == yTileCount - 1) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallright.png", k, n, false));
                } else if (j == xTileCount - 1) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomright.png", k, n, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottom.png", k, n, false));
                }
            } else if (i != 0 && j == 0) {
                row.push_back(new RoomTile("content/sprites/walls/topwallLEFTSIDE.png", k, n, false));
            } else if (i != 0 && j == xTileCount - 1) {
                row.push_back(new RoomTile("content/sprites/walls/topwallRIGHTSIDE.png", k, n, false));

            } else {
                row.push_back(new RoomTile("content/sprites/floors/tile1.png", k, n, true, true));
            }
            k += 64;
        }
        n += 64;
        tileVector_.push_back(row);
    }
}
