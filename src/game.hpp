#pragma once

#ifndef _GAME_CLASS_
#define _GAME_CLASS_

#include "Actors/Monsters/MonsterSpawner/MonsterSpawner.hpp"
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
    RoomInstance* room; // otherwise fails due to some werid deleted function thing
    Player* player_;
    Gamebar gamebar_;

    float dt;
    bool paused = false;
    bool gameEnder_;

    std::list<Monster*> monsters_;
    std::list<Projectile*> projectiles_;
    // CollisionSystem collisionSys;

    void initVariables();
    void initWindow();
    void updateDt();
    void manageInput();
    void checkCollisions(Character* character, Projectile::Type projectileType);
    void checkMonsterCollisions();
    void checkPlayerCollisions();
    void checkAndHandleProjectileWallCollisions();
    void deleteProjectile(Projectile* p);
    void deleteMonster(Character* m);
    void updateProjectiles();
    bool collidesWithWall(Character* character);
    bool collidesWithWall(Entity* object);
    bool gameLost();
};

#endif