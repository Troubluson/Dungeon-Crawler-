

#include "Actors/player.hpp"
#include "Dungeon/Map.hpp"
#include "Dungeon/RoomInstance.hpp"

#include "Catch2/catch.hpp"

TEST_CASE("Testing Rooms and spawning")
{
    auto s = sf::Vector2u(1000, 1000);
    PlayerPS player(new Player());
    REQUIRE(player->Attack(sf::Vector2f(s)).empty());

    RoomInstance room = RoomInstance(s, sf::Vector2i(0, 0));
    REQUIRE(room.GetMonsters().empty());
    room.Enter(player, Direction::Up);
    REQUIRE_FALSE(room.GetMonsters().empty());
    for (auto m : room.GetMonsters()) {
        REQUIRE(m->GetPlayer().GetPos() == (*player).GetPos());
    }

    return;
}