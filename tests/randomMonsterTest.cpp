#define CATCH_CONFIG_MAIN

#include "Actors/Monsters/RandomMonster.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("Testing constructor")
{
    Player p = Player();
    RandomMonster rm = RandomMonster(p, sf::Vector2f(400, 400));
    REQUIRE(rm.GetPos() == sf::Vector2f(400, 400));
}
