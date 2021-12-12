#include "map.hpp"
#include <time.h>

Map::Map(sf::Vector2u size, int noRooms, PlayerPS player)
    : roomSize_(size)
    , currentPos_({ 0, 0 })
    , player_(player)
    , spawnChoords_(currentPos_)
{
    srand(time(NULL));
    while (!CreateDungeon(noRooms))
        ; // dungeon creation can fail
    std::map<std::pair<int, int>, RoomInstance*>::iterator it;
    for (it = dungeon_.begin(); it != dungeon_.end(); it++) {
        it->second->renderSpriteBackground();
    }
}

void Map::RenderCurrentRoom(sf::RenderTarget* window)
{

    GetCurrentRoom()->Render(window);
}

bool Map::CreateDungeon(int noRooms)
{
    addStartingRoomToDungeon(roomSize_, currentPos_);
    int i = 1;
    std::map<std::pair<int, int>, std::set<Direction>> wallsToBreak;
    while (i < noRooms) {
        std::pair<int, int> coordsToGenFrom = existingRoomCords_[randomhelper::RandomIntBetween(0, existingRoomCords_.size() - 1)];
        RoomInstance* roomToGenFrom = dungeon_[coordsToGenFrom];

        if (roomToGenFrom->HasDirectionsLeft()) {
            Direction directionToGenInto = roomToGenFrom->UseDirection();
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
    dungeon_[bossCoords] = bossRoom;

    for (auto room : wallsToBreak) {
        for (auto dir : room.second) {
            dungeon_[room.first]->CreateExit(dir);
        }
    }

    currentPos_ = { 0, 0 };

    return true;
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

RoomInstance* Map::GetRoomAt(sf::Vector2i choord)
{
    if (dungeon_.count(getKey(choord))) {
        return dungeon_[getKey(choord)];
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
    return dungeon_[getKey(spawnChoords_)];
}

std::pair<int, int> Map::findBossRoom(std::map<std::pair<int, int>, std::set<Direction>> coordsAndPaths)
{
    std::pair<int, int> maxCoord = std::make_pair(0, 0);
    for (auto it = coordsAndPaths.begin(); it != coordsAndPaths.end(); it++) {
        auto coord = it->first;
        auto biggerCoord = max(abs(coord.first), abs(coord.second));
        if (biggerCoord > max(abs(maxCoord.first), abs(maxCoord.second)) && it->second.size() == 1) {
            maxCoord = coord;
        }
    }
    return maxCoord;
}

std::pair<int, int> Map::getKey()
{
    return std::make_pair(currentPos_.x, currentPos_.y);
}
std::pair<int, int> Map::getKey(sf::Vector2i choord)
{
    return std::make_pair(choord.x, choord.y);
}

RoomInstance* Map::addRoomToDungeon(sf::Vector2u roomSize, sf::Vector2i choords)
{
    RoomInstance* room = new RoomInstance(roomSize, choords);
    if (room == nullptr) {
        std::cout << "lol" << std::endl;
    }
    existingRoomCords_.push_back(getKey(choords));
    dungeon_[getKey(choords)] = room;
    return room;
}

void Map::addStartingRoomToDungeon(sf::Vector2u roomSize, sf::Vector2i choords)
{
    RoomInstance* rootRoom = new StartingRoom(roomSize, choords);
    existingRoomCords_.push_back(getKey(choords));
    std::cout << existingRoomCords_.size() << std::endl;
    dungeon_[getKey(choords)] = rootRoom;
}
