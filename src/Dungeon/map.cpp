#include "map.hpp"
#include <time.h>

Map::Map(sf::Vector2u size, int noRooms, PlayerPS player)
    : roomSize_(size)
    , currentPos_({ 0, 0 })
    , player_(player)
    , spawnCoords_(currentPos_)
{
    srand(time(NULL));
    CreateDungeon(noRooms);
    std::map<std::pair<int, int>, RoomInstance*>::iterator it;
    for (it = dungeon_.begin(); it != dungeon_.end(); it++) {
        it->second->renderSpriteBackground();
    }
}

void Map::RenderCurrentRoom(sf::RenderTarget* window)
{

    GetCurrentRoom()->Render(window);
}

void Map::CreateDungeon(int noRooms)
{
    addStartingRoomToDungeon(roomSize_, currentPos_);
    int i = 1;
    std::map<std::pair<int, int>, std::set<Direction>> wallsToBreak;
    while (i < noRooms) {
        RoomInstance* roomToGenFrom = getRandomRoom();

        if (roomToGenFrom->HasDirectionsLeft()) {

            Direction directionToGenInto = roomToGenFrom->RemoveRandomDirection();
            auto newPos = roomToGenFrom->GetCoords() + DirToVec(directionToGenInto);
            if (GetRoomAt(newPos) == nullptr) {
                auto newRoom = addRoomToDungeon(roomSize_, newPos);
                wallsToBreak[getKey(roomToGenFrom->GetCoords())].insert(directionToGenInto);
                wallsToBreak[getKey(newRoom->GetCoords())].insert((direction::GetOppositeDir(directionToGenInto)));

                i += 1;
            }
        }
    }

    auto bossCoords = findBossRoom(wallsToBreak);
    RoomInstance* bossRoom = new BossRoom(roomSize_, sf::Vector2i(bossCoords.first, bossCoords.second));
    delete dungeon_[bossCoords];
    dungeon_[bossCoords] = bossRoom;

    for (auto room : wallsToBreak) {
        for (auto dir : room.second) {
            dungeon_[room.first]->CreateExit(dir);
        }
    }

    currentPos_ = { 0, 0 };
}

void Map::MovePlayer(Direction dir)
{
    GetCurrentRoom()->Exit();
    Move(dir);
    GetCurrentRoom()->Enter(player_, dir);
}

void Map::Move(Direction dir)
{
    currentPos_ += DirToVec(dir);
}

RoomInstance* Map::GetRoomAt(sf::Vector2i coord)
{
    if (dungeon_.count(getKey(coord))) {
        return dungeon_[getKey(coord)];
    }
    return nullptr;
}

RoomInstance* Map::GetRoomInDir(Direction dir)
{
    auto oldPos = currentPos_;
    Move(dir);
    RoomInstance* room = nullptr;
    if (dungeon_.count(getKey())) {
        room = dungeon_[getKey()];
    }
    currentPos_ = oldPos;
    return room;
}

sf::Vector2i Map::DirToVec(Direction direction)
{
    switch (direction) {
    case Direction::Up:
        return sf::Vector2i(0, 1);
    case Direction::Down:
        return sf::Vector2i(0, -1);
    case Direction::Left:
        return sf::Vector2i(-1, 0);
    case Direction::Right:
        return sf::Vector2i(1, 0);
    default:
        return sf::Vector2i(0, 0);
    }
}

RoomInstance* Map::GetCurrentRoom()
{
    return dungeon_[getKey()];
}

RoomInstance* Map::GetSpawnRoom()
{
    return GetRoomAt(spawnCoords_);
}

bool Map::IsBossRoomCleared()
{
    return GetRoomAt(bossCoords_)->IsCleared();
}

std::pair<int, int> Map::findBossRoom(std::map<std::pair<int, int>, std::set<Direction>> coordsAndPaths)
{
    std::pair<int, int> maxCoord = std::make_pair(0, 0);

    size_t allowedBossRoomEntrances = 1;
    while (maxCoord.first == 0 && maxCoord.second == 0) {
        for (auto it = coordsAndPaths.begin(); it != coordsAndPaths.end(); it++) {
            auto coord = it->first;
            if (abs(coord.first) > abs(maxCoord.first) && abs(coord.second) > abs(maxCoord.second) && it->second.size() <= allowedBossRoomEntrances) {
                maxCoord = coord;
            }
        }
        allowedBossRoomEntrances += 1;
    }

    return maxCoord;
}

std::pair<int, int> Map::getKey()
{
    return std::make_pair(currentPos_.x, currentPos_.y);
}
std::pair<int, int> Map::getKey(sf::Vector2i coord)
{
    return std::make_pair(coord.x, coord.y);
}

RoomInstance* Map::getRandomRoom()
{
    std::pair<int, int> coordsToGenFrom = existingRoomCoords_[randomhelper::RandomIntBetween(0, existingRoomCoords_.size() - 1)];
    RoomInstance* roomToGenFrom = dungeon_[coordsToGenFrom];
    return roomToGenFrom;
}

RoomInstance* Map::addRoomToDungeon(sf::Vector2u roomSize, sf::Vector2i coords)
{
    RoomInstance* room = new RoomInstance(roomSize, coords);
    existingRoomCoords_.push_back(getKey(coords));
    dungeon_[getKey(coords)] = room;
    return room;
}

void Map::addStartingRoomToDungeon(sf::Vector2u roomSize, sf::Vector2i coords)
{
    RoomInstance* rootRoom = new StartingRoom(roomSize, coords);
    existingRoomCoords_.push_back(getKey(coords));
    std::cout << existingRoomCoords_.size() << std::endl;
    dungeon_[getKey(coords)] = rootRoom;
}

void Map::ResetMap()
{
    currentPos_ = { 0, 0 };
}