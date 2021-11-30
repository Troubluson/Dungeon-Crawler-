#pragma once

#ifndef _GAME_CLASS_
#define _GAME_CLASS_

#include "Actors/RandomMonster.hpp"
#include "Actors/SearchingMonster.hpp"
#include "Actors/monster.hpp"
#include "Actors/player.hpp"
#include "roomInstance.hpp"
/*#include "CollisionSystem.hpp"*/
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
    Gamebar gamebar_;

    float dt;
    bool paused = false;
    bool gameEnder_;

    std::vector<Character*> monsters_;
    std::vector<Projectile*> projectiles_;
    // CollisionSystem collisionSys;

    void initVariables();
    void initWindow();
    void updateDt();
    void manageInput();
    void checkCollisions(std::vector<Character*> characterVector, Projectile::Type type);
    void checkAndHandleProjectileWallCollisions();
    void deleteProjectile(Projectile* p);
    void addProjectiles(std::vector<Projectile*> listToAdd);
    void deleteMonster(Character* m);
    void updateProjectiles();
    bool collidesWithWall(Character* character);
    bool collidesWithWall(Entity* object);
};

#endif