
#include "entity.hpp"
#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("Testing Entity constructor")
{
    Entity e = Entity("content/sprites/characters/SpriteSheet.png", sf::Vector2f(200, 200), sf::Vector2f(1, 1));
    REQUIRE(e.GetPos() == sf::Vector2f(200, 200));
    REQUIRE(e.GetSprite().getPosition() == e.GetPos());
}