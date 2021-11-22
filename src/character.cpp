#include "character.hpp"
#define C_PIXELS 64

Character::Character(const std::string& filename, const sf::Vector2f& pos, bool isPlayer)
{
    pos_ = pos;
    oldPos_ = pos_;
    dt_ = {1.0f / 60.0f};
    isPlayer_ = isPlayer;
    if (isPlayer_ == true) {
        sprite_.setTextureRect({0,0,C_PIXELS,C_PIXELS});
        sprite_.setScale(sf::Vector2f(2, 2));
        Animations[int(AnimationIndex::AnimationUp)] = new Animation(C_PIXELS , 0 , C_PIXELS, C_PIXELS,  filename);
        Animations[int(AnimationIndex::AnimationDown)] = new Animation(C_PIXELS ,C_PIXELS * 4 , C_PIXELS, C_PIXELS,  filename);
        Animations[int(AnimationIndex::AnimationLeft)] = new Animation(C_PIXELS ,C_PIXELS * 2, C_PIXELS, C_PIXELS,  filename);
        Animations[int(AnimationIndex::AnimationRight)] = new Animation(C_PIXELS ,C_PIXELS * 3 , C_PIXELS, C_PIXELS,  filename);
        Animations[int(AnimationIndex::AnimationIdle)] = new Animation(C_PIXELS ,C_PIXELS , C_PIXELS, C_PIXELS,  filename);
    }

    else {
        initSprite(filename);
    }



}


Character::~Character() { }

void Character::Update() {

    if (isPlayer_ == true)
    {
        if (oldPos_ == pos_)
        {
            Idle();
        }
        Animations[int(currentAnimation)]->Update(dt_);
        Animations[int(currentAnimation)]->AnimationToSprite(sprite_);
    }
    oldPos_ = pos_;
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



bool Character::MoveLeft()
{
    pos_.x -= speed_;
    currentAnimation = AnimationIndex::AnimationLeft;

    return true;
}

bool Character::MoveRight()
{
    pos_.x += speed_;

    currentAnimation = AnimationIndex::AnimationRight;

    return true;
}

bool Character::MoveDown()
{
    pos_.y += speed_;
    currentAnimation = AnimationIndex::AnimationDown;

    return true;
}

bool Character::MoveUp()
{
    pos_.y -= speed_;
    currentAnimation = AnimationIndex::AnimationUp;

    return true;
}


bool Character::Idle()
{
    currentAnimation = AnimationIndex::AnimationIdle;
    return true;
}