#define CATCH_CONFIG_MAIN

#include "Actors/Monsters/RandomMonster.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("Testing RandomMonster constructor")
{
    Player p = Player();
    RandomMonster rm = RandomMonster(p, sf::Vector2f(400, 400));
    REQUIRE(rm.GetPos() == sf::Vector2f(400, 400));
}

TEST_CASE("Testing RandomMonster move")
{
    Player p = Player();
    RandomMonster rm = RandomMonster(p, sf::Vector2f(400, 400));
    rm.Move(0.1);
    REQUIRE(rm.GetPos() == sf::Vector2f(400, 420));
}