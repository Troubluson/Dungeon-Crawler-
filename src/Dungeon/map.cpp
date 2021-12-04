#include "map.hpp"
#include <time.h>

namespace {
Direction GetOppositeDir(Direction dir)
{
    switch (dir) {
    case Direction::Up:
        return Direction::Down;
    case Direction::Down:
        return Direction::Up;
    case Direction::Left:
        return Direction::Right;
    case Direction::Right:
        return Direction::Left;
    default:
        return Direction::Up;
    }
}
} // namespace

Map::Map(sf::Vector2u size, uint noRooms)
    : roomSize_(size)
    , currentPos_({ 0, 0 })
{
    srand(time(NULL)); // create random seed for this map
    CreateDungeon(noRooms);
}

void Map::loadRoom(sf::RenderTarget* window)
{
    auto room = dungeon_[getKey()];
    room->Render(window);
}

void Map::nextRoom()
{
    if (room < 4) {
        room += 1;
    }
}

void Map::CreateDungeon(uint noRooms)
{
    RoomInstance* currentRoom = new StartingRoom(roomSize_);
    dungeon_[getKey()] = currentRoom;
    spawn_ = currentRoom;
    auto i = 1u;
    while (i < noRooms) {
        int dirCount = static_cast<int>(Direction::Count);
        auto dirIdx = rand() % dirCount;
        auto dir = Direction(dirIdx); // get random dir
        if (GetRoomInDir(dir) == nullptr) {
            // move map to new room
            Move(dir);
            auto newRoom = new RoomInstance(roomSize_);
            dungeon_[getKey()] = currentRoom;

            // check which rooms to connect
            for (auto j = 0; j < dirCount; ++j) {
                auto roomInDir = GetRoomInDir(Direction(j));
                if (roomInDir != nullptr) {
                    currentRoom->CreateExit(dir);
                    roomInDir->CreateExit(GetOppositeDir(dir));
                }
            }
            currentRoom = newRoom;
            ++i;
        } else {
            currentRoom = GetRoomInDir(dir);
        }
    }
}

RoomInstance* Map::GetRoom()
{
    return dungeon_[getKey()];
}

void Map::Move(Direction dir)
{
    switch (dir) {
    case Direction::Up:
        ++currentPos_.y;
        break;
    case Direction::Down:
        --currentPos_.y;
        break;
    case Direction::Left:
        --currentPos_.x;
        break;
    case Direction::Right:
        ++currentPos_.x;
        break;
    default:
        break;
    }
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

std::pair<int, int> Map::getKey()
{
    return std::make_pair(currentPos_.x, currentPos_.y);
}
