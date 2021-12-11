#include "game.hpp"
#include "Collision.hpp"
#define C_PIXELS 64

namespace {
const sf::Vector2u VIDEOMODE_DIMS = sf::Vector2u(1280, 768);
}

Game::Game()
    : player_(new Player())
    , dungeonMap_(Map(VIDEOMODE_DIMS, 10, *player_))
    , gamebar_(Gamebar(player_))
{
    srand(sf::Mouse::getPosition().y);
    SwordWeapon* sword = new SwordWeapon(20, 10, sf::Vector2f(50, 100), 120, "content/sprites/projectiles.png");
    player_->Equip(sword);
    initVariables();
    initWindow();
    dtClock.restart(); // to not have giant first dt
}

Game::~Game()
{
    delete window_;
    delete player_;
}

void Game::UpdateGame()
{
    Events();

    updateDt();
    manageInput();

    // Update projectiles
    for (auto monster : dungeonMap_.GetCurrentRoom()->GetMonsters()) {
        // if moved, check collision with walls
        bool monsterMoved = monster->Move(dt);
        if (monsterMoved && collidesWithWall(monster)) {
            monster->RevertMove();
        }

        std::list<Projectile*> projectileListToAdd = monster->Attack();
        addProjectiles(projectileListToAdd);

        monster->Update(dt);
    }

    for (auto potion : dungeonMap_.GetCurrentRoom()->GetPotions()) {
        sf::Vector2f poPos = potion->GetSpriteCenter();
        sf::Vector2f plPos = player_->GetSpriteCenter();
        sf::Vector2f difference = poPos - plPos;
        float distance = std::sqrt(difference.x * difference.x + difference.y * difference.y);
        if (distance < 50) {
            player_->AddPotion(potion);
            deletePotion(potion);
        }
    }
    updateProjectiles();
    // checkCollisions(player_, Projectile::Type::EnemyProjectile);
    // handleMonsterProjectileCollisions(monsters_, Projectile::Type::PlayerProjectile);
    checkMonsterCollisions();
    checkPlayerCollisions();
    checkAndHandleProjectileWallCollisions();
    player_->Update(dt);
    gamebar_.Update();
}
// render game frames
void Game::RenderGame()
{
    window_->clear();
    dungeonMap_.RenderCurrentRoom(window_);
    player_->Render(window_);
    gamebar_.Render(window_);
    for (auto projectile : projectiles_) {
        projectile->Render(window_);
    }
    for (auto monster : dungeonMap_.GetCurrentRoom()->GetMonsters()) {
        if (monster == nullptr) {
            std::cout << "nullptr" << std::endl;
        }
        monster->Render(window_);
    }
    for (auto potion : dungeonMap_.GetCurrentRoom()->GetPotions()) {
        potion->Render(window_);
    }
    window_->display();
}
bool Game::Running() const { return window_->isOpen(); }

void Game::Events()
{
    while (window_->pollEvent(event_)) {
        switch (event_.type) {
        case sf::Event::Closed:
            window_->close();
            break;
        case sf::Event::LostFocus:
            paused = true;
            break;
        case sf::Event::GainedFocus:
            paused = false;
            break;
        case sf::Event::KeyPressed:
            if (event_.key.code == sf::Keyboard::Num1)
                player_->UsePotion("red");
            else if (event_.key.code == sf::Keyboard::Num2)
                player_->UsePotion("green");
            else if (event_.key.code == sf::Keyboard::Num3)
                player_->UsePotion("yellow");
            else if (event_.key.code == sf::Keyboard::Num4)
                player_->UsePotion("violet");
            break;
        default:
            break;
        }
    }
}

void Game::initVariables() { gameEnder_ = false; }
// initalize window
void Game::initWindow()
{
    // gets resolution and etc.
    auto desktopMode = sf::VideoMode::getDesktopMode();
    videomode_ = sf::VideoMode(std::min(VIDEOMODE_DIMS.x, desktopMode.width), std::min(VIDEOMODE_DIMS.y, desktopMode.height));
    window_ = new sf::RenderWindow(videomode_, "Dungeon Crawler");
}

void Game::updateDt() { dt = dtClock.restart().asSeconds(); }

void Game::manageInput()
{
    bool W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool LSHIFT = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
    bool LMOUSE = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    bool twoKeys = ((W || S) && (A || D));
    bool triedMoving = W || A || S || D;

    if (twoKeys) {
        if (A) {
            player_->MoveLeft(dt / sqrt(2));
        } else if (D) {
            player_->MoveRight(dt / sqrt(2));
        }

        if (W) {
            player_->MoveUp(dt / sqrt(2));
        } else if (S) {
            player_->MoveDown(dt / sqrt(2));
        }
    } else {
        if (A) {
            player_->MoveLeft(dt);
        } else if (D) {
            player_->MoveRight(dt);
        }

        if (W) {
            player_->MoveUp(dt);
        } else if (S) {
            player_->MoveDown(dt);
        }
    }

    if (LSHIFT) {
        player_->Dash();
    }

    if (LMOUSE) {
        sf::Vector2f mousePos = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
        std::list<Projectile*> projectileListToAdd = player_->Attack(mousePos);
        addProjectiles(projectileListToAdd);
    }
    if (triedMoving) {
        // std::cout << player_->GetPos().x << " " << player_->GetPos().y << std::endl;
        if (collidesWithWall(player_)) {
            player_->RevertMove();
        }
        if (ShouldChangeRoom()) {
            std::cout << dungeonMap_.GetCurrentRoom()->GetChoords().x << " , " << dungeonMap_.GetCurrentRoom()->GetChoords().y << std::endl;
            float y = window_->getSize().y;
            float x = window_->getSize().x;
            if (player_->GetPos().y <= 0) {
                player_->setPos({ player_->GetPos().x, y - 3 });
            }
            if (player_->GetPos().y > y) {
                player_->setPos({ player_->GetPos().x, -3 });
            }
            if (player_->GetPos().x <= 0) {
                player_->setPos({ x - 3, player_->GetPos().y });
            }
            if (player_->GetPos().x > x) {
                player_->setPos({ -3, player_->GetPos().y });
            }
        }
    }
}

void Game::checkCollisions(Character* character, Projectile::Type projectileType)
{
    for (auto projectile : projectiles_) {
        if (projectile->GetType() == projectileType && !projectile->hasHit(character)) {
            if (Collision::PixelPerfectTest(projectile->GetSprite(), character->GetSprite())) {
                projectile->hit(character);
                character->TakeDamage(projectile->GetDamage());
                if (!projectile->Penetrates()) {
                    projectile->Kill();
                }
            }
        }
    }
}

void Game::checkMonsterCollisions()
{
    if (projectiles_.empty()) {
        return;
    }
    std::vector<Monster*> deadMonsters;
    for (auto& monster : dungeonMap_.GetCurrentRoom()->GetMonsters()) {
        checkCollisions(monster, Projectile::Type::PlayerProjectile);
        if (!monster->IsAlive()) {
            deadMonsters.push_back(monster);
            Potion* potion = monster->ReturnPotion();
            if (potion != nullptr) {
                dungeonMap_.GetCurrentRoom()->AddPotion(potion);
            }
        }
    }
    for (auto monster : deadMonsters) {
        deleteMonster(monster);
    }
}

void Game::checkPlayerCollisions()
{
    if (projectiles_.empty()) {
        return;
    }
    checkCollisions(player_, Projectile::Type::EnemyProjectile);
}

void Game::checkAndHandleProjectileWallCollisions()
{
    for (auto projectile : projectiles_) {
        if (collidesWithWall(projectile)) {
            projectile->Kill();
        }
    }
}
// redundant atm
void Game::deleteProjectile(Projectile* p)
{
    if (projectiles_.empty())
        return;

    for (auto it = projectiles_.begin(); it != projectiles_.end(); ++it) {
        if (*it == p) {
            projectiles_.erase(it);
            return;
        }
    }
}

void Game::addProjectiles(std::list<Projectile*> projectiles)
{
    if (projectiles.empty()) {
        return;
    }

    for (auto projectile : projectiles) {
        projectiles_.push_back(projectile);
    }
}

void Game::deleteMonster(Character* m)
{
    auto& monsters = dungeonMap_.GetCurrentRoom()->GetMonsters();
    if (monsters.empty())
        return;

    for (auto it = monsters.begin(); it != monsters.end(); ++it) {
        if (*it == m) {
            delete *it;
            it = monsters.erase(it);
            return;
        }
    }
}

void Game::deletePotion(Potion* p)
{
    auto& potions = dungeonMap_.GetCurrentRoom()->GetPotions();
    if (potions.empty())
        return;

    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (*it == p) {
            it = potions.erase(it);
            return;
        }
    }
}

void Game::updateProjectiles()
{
    if (projectiles_.empty())
        return;

    for (auto it = projectiles_.begin(); it != projectiles_.end(); ++it) {
        auto p = *it;
        if (!p->IsAlive()) {
            it = projectiles_.erase(it);
        } else {
            p->Update(dt);
        }
    }
}
bool Game::collidesWithWall(Character* character)
{
    return !dungeonMap_.GetCurrentRoom()->positionIsWalkable(character->GetBaseBoxAt(character->GetPos()));
}
bool Game::collidesWithWall(Entity* object)
{
    return !dungeonMap_.GetCurrentRoom()->positionIsWalkable(object->getSpriteBounds());
}

bool Game::ShouldChangeRoom()
{
    if (videomode_.width < player_->GetPos().x) {
        dungeonMap_.MovePlayer(Direction::Right);
        return true;
    } else if (player_->GetPos().x + player_->getSpriteBounds().width < 0) {
        dungeonMap_.MovePlayer(Direction::Left);
        return true;
    } else if (player_->GetPos().y + player_->getSpriteBounds().height < 0) {
        dungeonMap_.MovePlayer(Direction::Up);
        return true;
    } else if (player_->GetPos().y > videomode_.height) {
        dungeonMap_.MovePlayer(Direction::Down);
        return true;
    }
    return false;
}

bool Game::gameLost()
{
    return player_->IsAlive();
}
