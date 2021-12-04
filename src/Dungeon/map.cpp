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
    std::map<std::pair<int, int>, RoomInstance*>::iterator it;
    for (it = dungeon_.begin(); it != dungeon_.end(); it++) {
        it->second->renderSpriteBackground(size);
    }
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
    RoomInstance* currentRoom = new StartingRoom(roomSize_, currentPos_);
    dungeon_[getKey()] = currentRoom;
    spawn_ = currentRoom;
    auto i = 1u;
    int dirCount = static_cast<int>(Direction::Count);

    // NOTE: currentPos will be the position of the new room when looping
    while (i < noRooms) {
        auto dirIdx = rand() % dirCount;
        auto dir = Direction(dirIdx); // get random dir
        // move map to new room
        Move(dir);
        if (GetRoomAt(currentPos_) == nullptr) { // should we create a new room
            auto newRoom = new RoomInstance(roomSize_, currentPos_);
            dungeon_[getKey(currentPos_)] = newRoom;
            std::cout << getKey(currentPos_).first << "," << getKey(currentPos_).second << std::endl;
            std::cout << "dir: " << static_cast<int>(dir) << std::endl;

            // check which rooms to connect
            for (auto j = 0; j < dirCount; ++j) {
                auto roomInDir = GetRoomAt(currentRoom->GetChoords() + DirToVec(Direction(j)));
                if (roomInDir != nullptr) {
                    std::cout << "Creating exit for: " << currentRoom->GetChoords().x << "," << currentRoom->GetChoords().y << " in dir: " << j << std::endl;
                    currentRoom->CreateExit(Direction(j));
                    roomInDir->CreateExit(GetOppositeDir(Direction(j)));
                }
            }
            currentRoom = newRoom;
            ++i;

        } else {
            currentRoom = GetRoomAt(currentPos_);
        }
    }
    currentPos_ = { 0, 0 }; // reset position
}

RoomInstance* Map::GetRoom()
{
    // std::cout << getKey().first << "," << getKey().second << std::endl;
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

std::pair<int, int> Map::getKey()
{
    return std::make_pair(currentPos_.x, currentPos_.y);
}
std::pair<int, int> Map::getKey(sf::Vector2i choord)
{
    return std::make_pair(choord.x, choord.y);
}
