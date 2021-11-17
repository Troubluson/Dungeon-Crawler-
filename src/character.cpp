#include "character.hpp"


Character::Character(const std::string& filename, const sf::Vector2f& pos)
{
    pos_ = pos;
    dt_ = {1.0f / 6.0f};
    if (filename == "content/sprites/characters/spritesheet.png" ) {
        /*AnimationRight(61, 64 *2, 61, 64, filename);*/
        sprite_.setTextureRect({0,0,61,64});
    }




    initSprite(filename);



    tp = std::chrono::steady_clock::now();

}


Character::~Character() { }

void Character::Update() {
    getDt();
    pos_ += velocity_ * dt_;
    /*this->AnimationRight.Update(dt_);
    this->AnimationRight.AnimationToSprite(sprite_);*/
    sprite_.setPosition(pos_);
}

sf::Vector2f Character::GetPosition() { return sprite_.getPosition(); }

void Character::Render(sf::RenderTarget* target) { target->draw(sprite_); }

void Character::initSprite(const std::string& filename)
{
    if (texture_.loadFromFile(filename)) {
        sprite_.setTexture(texture_);

        sprite_.setScale(sf::Vector2f(2, 2));
    }
}

void Character::Direction(const sf::Vector2f dir)
{
    velocity_ = dir * speed_;
}

bool Character::MoveLeft()
{
    dir_.x -= 1.0f;
    this->Direction(dir_);
    return true;
}

bool Character::MoveRight()
{
    dir_.x += 1.0f;
    this->Direction(dir_);
    return true;
}

bool Character::MoveDown()
{
    dir_.y += 1.0f;
    this->Direction(dir_);
    return true;
}

bool Character::MoveUp()
{
    dir_.y -= 1.0f;
    this->Direction(dir_);
    return true;
}

void Character::getDt()
{
	const auto new_tp = std::chrono::steady_clock::now();
	dt_ = std::chrono::duration<float>(new_tp - tp).count();
	tp = new_tp;
}