#include "map.hpp"
#include <time.h>

namespace {
Direction GetOppositeDir(Direction direction)
{
    switch (direction) {
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

Map::Map(sf::Vector2u size, int noRooms)
    : roomSize_(size)
    , currentPos_({ 0, 0 })
{
    while(!CreateDungeon(noRooms)); //dungeon creation can fail
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
    RoomInstance* rootRoom = new StartingRoom(roomSize_, currentPos_);
    dungeon_[getKey()] = rootRoom;
    spawn_ = rootRoom;
    auto i = 1;
    int dirCount = static_cast<int>(Direction::Count);
    int retryCount = 0;
    // NOTE: currentPos will be the position of the new room when looping
    while (i < noRooms) {
        auto dirIdx = rand() % dirCount;
        auto dir = Direction(dirIdx); // get random dir
        // move map to new room
        Move(dir);
        // should we create a new room, we try to not make it too snake-like
        if (abs(rootRoom->GetChoords().x) <= noRooms / 3 && abs(rootRoom->GetChoords().y) <= int(noRooms) / 3) {

            if (GetRoomAt(currentPos_) == nullptr) {
                retryCount = 0;
                auto newRoom = new RoomInstance(roomSize_, currentPos_);
                dungeon_[getKey(currentPos_)] = newRoom;

                // check which rooms to "connect"
                for (auto j = 0; j < dirCount; ++j) {
                    auto roomInDir = GetRoomAt(rootRoom->GetChoords() + DirToVec(Direction(j)));
                    if (roomInDir != nullptr) {
                        rootRoom->CreateExit(Direction(j));
                        roomInDir->CreateExit(GetOppositeDir(Direction(j)));
                    }
                }
                rootRoom = newRoom;
                ++i;

            } else {
                rootRoom = GetRoomAt(currentPos_); // move to the room that we already have connected to
            }
        } else { // we go back to spawn
            currentPos_ = { 0, 0 };
            retryCount += 1;
            if(retryCount == 4) {
                return false;
            }
        }
    }
    currentPos_ = { 0, 0 }; // reset position to spawnroom
    return true;
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

std::pair<int, int> Map::getKey()
{
    return std::make_pair(currentPos_.x, currentPos_.y);
}
std::pair<int, int> Map::getKey(sf::Vector2i choord)
{
    return std::make_pair(choord.x, choord.y);
}
