#include "character.hpp"

Character::Character(const std::string& filename, float xPos, float yPos)
    : Entity(filename, xPos, yPos, 3)
{
}

Character::~Character() { }

void Character::Update() { sprite_.setPosition(xPos_, yPos_); }

sf::Vector2f Character::GetPosition() { return sprite_.getPosition(); }
