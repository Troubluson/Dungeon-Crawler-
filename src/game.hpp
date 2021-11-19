#pragma once

#ifndef _GAME_CLASS_
#define _GAME_CLASS_

#include "monster.hpp"
#include "player.hpp"
#include "projectile.hpp"
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
    bool gameEnder_;
    sf::Event event_;
    RoomInstance room;
    Player* player_;

    void initVariables();
    void initWindow();
    void updateDt();

    sf::Clock dtClock;
    float dt;

    bool paused = false;
    void manageInput();

    std::vector<Character*> monsterVector_;
    std::vector<Projectile*> projectileVector;

    void checkCollisions(std::vector<Character*> characterVector, Projectile::Type type);
    void checkWallCollisions();
    void deleteProjectile(Projectile* p);
    void deleteMonster(Monster* m);
    void updateProjectiles();
};

#endif