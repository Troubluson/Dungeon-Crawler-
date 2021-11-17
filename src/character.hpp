

#ifndef _CHARACTER_CLASS_
#define _CHARACTER_CLASS_

#include "animation.hpp"
#include <chrono>


class Character {
public:
    Character(const std::string& filename, const sf::Vector2f& pos_);

    ~Character();

    void Update();

    void Render(sf::RenderTarget* target);

    void initSprite(const std::string& filename);
    void Direction(const sf::Vector2f dir);

    bool MoveLeft();
    bool MoveRight();
    bool MoveDown();
    bool MoveUp();
    void getDt();
    void initVariables();
    sf::Vector2f GetPosition();

private:

    sf::Sprite sprite_;
    sf::Texture texture_;
    sf::Vector2f pos_;
    sf::Vector2f dir_ = {0.0f, 0.0f};
    sf::Vector2f velocity_ = {0.0f, 0.0f};
    static constexpr float speed_ = 3.0f;
    float dt_ = 0;
    std::chrono::_V2::steady_clock::time_point tp;

    /*Animation AnimationRight;*/

};

#endif
