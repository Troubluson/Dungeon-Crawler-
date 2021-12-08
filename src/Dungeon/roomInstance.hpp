
#include "Actors/Monsters/MonsterSpawner/MonsterSpawner.hpp"
#include "Combat/Health/HealthPotion.hpp"
#include "roomTile.hpp"

#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

enum class Direction {
    Up,
    Down,
    Left,
    Right,
    Count
};
/**
 * @brief Class representing a room of a dungeon, usually includes a monsterspawner.
 *
 */
class RoomInstance {
public:
    /**
     * @brief Construct a new Room Instance object
     *
     * @param    window_size          TO BE CHANGED takes the windowsize to create a correctly sized room
     * @param    choords              the map choordinate of the room, follows the cartesian choordinate system
     */
    RoomInstance(sf::Vector2u window_size, sf::Vector2i choords);
    RoomInstance() = default;
    ~RoomInstance();

    /**
     * @brief Renders the room
     *
     * @param    target               Where  to render the room. About always game window
     */
    void Render(sf::RenderTarget* target);

    std::vector<RoomTile*> getRoomTilesAt(sf::FloatRect bounds);

    bool positionIsWalkable(sf::FloatRect bounds);

    std::vector<std::vector<RoomTile*>> getTiles() const;

    /**
     * @brief Takes down a 2-wide in wall (replaces walls with floortiles) to be able to walk between two rooms
     *
     * @param    direction                  The direction of the exit
     */
    void CreateExit(Direction direction);

    /**
     * @brief Connects two rooms to each other
     *
     * @param    dir                  Direction where the new room resides
     * @param    room                 The new room
     * \note Also adds the rooms as a connection on the argument room's side
     */
    void Connect(Direction dir, RoomInstance* room);

    /**
     * @brief Returns the room found in the wanted direction, nullptr if it is not found
     *
     * @param    dir                  The direction
     * @return RoomInstance*
     */
    RoomInstance* GetRoomInDir(Direction dir);

    /**
     * @brief Get the choordinates of this room on the map
     *
     * @return sf::Vector2i
     */
    sf::Vector2i GetChoords() { return choords_; }

    /**
     * @brief Renders the rooms background to be a static backdrop, a very expensive operation
     */
    void renderSpriteBackground();

    /**
     * @brief Function called when entering a room, needs player as parameter to perform some calculations about room difficulty
     *
     * @param    player
     */
    void Enter(Player& player);

    /**
     * @brief Function called when exiting a room modifies cleared_ and visited_ booleans
     *
     */
    void Exit();

    std::vector<Monster*>& GetMonsters();

    void AddPotion(HealthPotion* potion);

    std::vector<HealthPotion*>& GetPotions();

protected:
    /**
     * @brief Helper, Sets all the roomtiles of the roominstance
     *
     */
    virtual void setTiles();
    sf::Vector2u roomSize_;
    sf::Vector2i choords_;
    std::vector<std::vector<RoomTile*>> tileVector_;
    sf::RenderTexture roomTexture;
    sf::Sprite roomBackground;
    std::vector<Monster*> monsters_;
    std::vector<HealthPotion*> healthPotions_;
    MonsterSpawner spawner_;
    bool cleared_; // whether the room is cleared
    bool visited_; // whether the room has been visited already
};

#endif
