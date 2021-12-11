#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Catch2/catch.hpp"
#include "entity.hpp"

TEST_CASE("Testing character")
{
    Character* c = new Player();

    // There should not be a need to write a test for all the private variables after construction.
    REQUIRE(c->GetPos() == sf::Vector2f(200, 200));
    REQUIRE(c->IsAlive() == true);
    REQUIRE(c->GetHitPoints() == 50);

    //float speed = 200;
    // Moving the character
    c->MoveDown(0.1);
}