
#ifndef _ROOM_INSTANCE_
#define _ROOM_INSTANCE_

#include "Actors/Monsters/MonsterSpawner/MonsterSpawner.hpp"
#include "Combat/Health/Potion.hpp"
#include "Tiles/roomTile.hpp"

enum class Direction {
    Up,
    Down,
    Left,
    Right,
    Count
};

namespace direction {
Direction GetOppositeDir(Direction direction);
}

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
     * @param    coords              the map coordinate of the room, follows the cartesian coordinate system
     */
    RoomInstance(sf::Vector2u window_size, sf::Vector2i coords);
    RoomInstance(sf::Vector2u window_size, sf::Vector2i coords, MonsterSpawner* spawner);
    RoomInstance() = default;
    virtual ~RoomInstance();

    /**
     * @brief Renders the room
     *
     * @param    target               Where  to render the room. About always game window
     */
    void Render(sf::RenderTarget* target);

    std::vector<RoomTile*> getRoomTilesAt(sf::FloatRect bounds);

    bool positionIsWalkable(sf::FloatRect bounds);
    bool positionIsPenetratable(sf::FloatRect bounds);

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
     * @brief Get the coordinates of this room on the map
     *
     * @return sf::Vector2i
     */
    sf::Vector2i GetCoords() { return coords_; }

    /**
     * @brief Renders the rooms background to be a static backdrop, a very expensive operation
     */
    void renderSpriteBackground();

    sf::Vector2u GetEntranceInDirection(Direction direction);

    /**
     * @brief Function called when entering a room, needs player as parameter to perform some calculations about room difficulty
     *
     * @param    player
     * @param    direction  the direction we enter from
     */
    virtual void Enter(PlayerPS player, Direction direction);

    /**
     * @brief Function called when exiting a room modifies cleared_ and visited_ booleans
     *
     */
    void Exit();

    std::vector<MonsterSP>& GetMonsters();

    void deleteMonster(MonsterSP m);

    /**
     * @brief Function used for Generating the dungeon map. Removes and returns a random Direction from the directionsLeft_ vector.
     *
     * @return Direction The Direction that was randomly chosen.
     */
    Direction RemoveRandomDirection();

    /**
     * @brief Function used for Generating the dungeon map. Removes the Direction dir from the directionsLeft_ vector.
     *
     * @param dir The Direction to remove.
     */
    void RemoveDirection(Direction dir);

    /**
     * @brief Function used for Generating the dungeon map. Checks if this roomInstance has any direction that does not already contain an other roomInstance.
     *
     * @return true Meaning that this roomInstance can be used to generate a new roomInstance
     * @return false Meaning that this roomInstance cannot be used to generate a new roomInstance
     */
    bool HasDirectionsLeft();

    /**
     * @brief Function the check if the roomInstance is cleared of Monsters
     *
     * @return true Meaning that this roomInstance is cleared of Monsters
     * @return false Meaning that this roomInstance is not cleared of Monsters
     */
    bool IsCleared();

    bool IsVisisted() {return visited_;}

    bool monsterCleared();

    void AddPotion(Potion* potion);

    std::vector<Potion*>& GetPotions();

protected:
    /**
     * @brief Helper, Sets all the roomtiles of the roominstance
     *
     */
    virtual void setTiles();
    sf::Vector2u roomSize_;
    sf::Vector2i coords_;
    std::vector<std::vector<RoomTile*>> tileVector_;
    sf::RenderTexture roomTexture;
    sf::Sprite roomBackground;
    std::vector<MonsterSP> monsters_;
    MonsterSpawner* spawner_;
    std::vector<Potion*> potions_;
    bool cleared_; // whether the room is cleared
    bool visited_; // whether the room has been visited already

    vector<Direction> directionsLeft_;
};

#endif
