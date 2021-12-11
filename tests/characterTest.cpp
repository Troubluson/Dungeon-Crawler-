#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Catch2/catch.hpp"
#include "entity.hpp"

TEST_CASE("Testing character")
{
    Character* c = new Player();
    REQUIRE(c->GetPos() == sf::Vector2f(200, 200));
    REQUIRE(c->IsAlive() == true);
    REQUIRE(c->GetHitPoints() == 50);
}