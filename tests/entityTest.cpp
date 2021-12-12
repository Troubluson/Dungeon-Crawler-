
#include "entity.hpp"
#include "Actors/character.hpp"
#include "Actors/player.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("Testing Entity")
{
    // Testing the constructor
    Entity e = Entity("content/sprites/monster1.png", sf::Vector2f(200, 200), sf::Vector2f(1, 1));
    REQUIRE(e.GetPos() == sf::Vector2f(200, 200));
    REQUIRE(e.GetSprite().getPosition() == e.GetPos());

    // Testing getSpriteCenter
    sf::FloatRect bounds = e.GetSpriteBounds();
    sf::Vector2f center = sf::Vector2f(e.GetPos().x + bounds.width / 2, e.GetPos().y + bounds.height / 2);
    REQUIRE(center == e.GetSpriteCenter());

    // Testing setOldandNewPos
    e.SetPosAndOldPos(sf::Vector2f(300, 300));
    bounds = e.GetSpriteBounds();
    center = sf::Vector2f(e.GetPos().x + bounds.width / 2, e.GetPos().y + bounds.height / 2);
    REQUIRE(e.GetPos() == sf::Vector2f(300, 300));
    REQUIRE(e.GetOldPosition() == sf::Vector2f(300, 300));
    // Entity is not currently updating the position of the sprite when the entity is given a new position.
    // This function is implemented in the generalUpdate function in the character class.
    // REQUIRE(center == e.GetSpriteCenter());

    // Testing SetPos
    e.SetPos(sf::Vector2f(200, 200));
    bounds = e.GetSpriteBounds();
    center = sf::Vector2f(e.GetPos().x + bounds.width / 2, e.GetPos().y + bounds.height / 2);
    REQUIRE(e.GetPos() == sf::Vector2f(200, 200));
    REQUIRE(e.GetOldPosition() == sf::Vector2f(300, 300));
    REQUIRE(center == e.GetSpriteCenter());
}
