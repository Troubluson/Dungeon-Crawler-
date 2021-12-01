#include "roomInstance.hpp"

class StartingRoom : public RoomInstance {
public:
    StartingRoom(sf::Vector2u window_size);
    StartingRoom() { }
    ~StartingRoom() { }
    virtual void setTiles(sf::Vector2u window_size);

private:
};