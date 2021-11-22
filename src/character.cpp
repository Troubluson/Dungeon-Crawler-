#include "character.hpp"


Character::Character(const std::string& filename, const sf::Vector2f& pos)
{
    pos_ = pos;
    oldPos_ = pos_;
    dt_ = {1.0f / 60.0f};

    if (filename == "content/spritesheet.png" ) {
        sprite_.setTextureRect({0,0,64,64});
        sprite_.setScale(sf::Vector2f(2, 2));
        Animations[int(AnimationIndex::AnimationUp)] = new Animation(64 , 0 , 64, 64,  filename);
        Animations[int(AnimationIndex::AnimationDown)] = new Animation(64 ,64 * 4 , 64, 64,  filename);
        Animations[int(AnimationIndex::AnimationLeft)] = new Animation(64 ,64 * 2, 64, 64,  filename);
        Animations[int(AnimationIndex::AnimationRight)] = new Animation(64 ,64 * 3 , 64, 64,  filename);
        Animations[int(AnimationIndex::AnimationIdle)] = new Animation(64 ,64 , 64, 64,  filename);
        player_char_ = true;
    }

    else {
        initSprite(filename);
    }

    tp = std::chrono::steady_clock::now();

}


Character::~Character() { }

void Character::Update() {
    getDt();

    if (player_char_ == true)
    {
        if ( oldPos_ == pos_)
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

void Character::getDt()
{
	const auto new_tp = std::chrono::steady_clock::now();
	dt_ = std::chrono::duration<float>(new_tp - tp).count();
	tp = new_tp;
}

bool Character::Idle()
{
    currentAnimation = AnimationIndex::AnimationIdle;
    return true;
}