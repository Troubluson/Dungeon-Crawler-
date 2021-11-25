#pragma once

#ifndef _GAME_CLASS_
#define _GAME_CLASS_

#include "Actors/monster.hpp"
#include "Actors/player.hpp"
#include "Combat/Projectile.hpp"
#include "Combat/Weapons/SwordWeapon.hpp"
#include "gamebar.hpp"
#include "roomInstance.hpp"

class Game {
public:
    Game();
    ~Game();

    void UpdateGame();

    void RenderGame();

    bool Running() const;

    void Events();

private:
    sf::VideoMode videomode_;
    sf::RenderWindow* window_;
    sf::Event event_;
    sf::Clock dtClock;
    RoomInstance room;
    Player* player_;

    float dt;
    bool paused = false;
    bool gameEnder_;

    std::list<Character*> monsters_;
    std::list<Projectile*> projectiles_;

    void initVariables();
    void initWindow();
    void updateDt();
    void manageInput();
    void checkCollisions(std::list<Character*> characterVector, Projectile::Type type);
    void checkWallCollisions();
    void deleteProjectile(Projectile* p);
    void deleteMonster(Character* m);
    void updateProjectiles();
};

#endif