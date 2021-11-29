#include "game.hpp"
#include "Collision.hpp"
#define C_PIXELS 64
namespace {
const sf::Vector2f PLACEHOLDER_PROJ_SIZE = sf::Vector2f(1.0, 1.0);
const int PLACEHOLDER_PROJ_SPEED = 1000;
const int PLACEHOLDER_PROJ_DIST = 20;
const int PLACEHOLDER_PROJ_DMG = 20;
const float PLACEHOLDER_PROJ_LS = 0.5;

}
Game::Game()
{
    player_ = new Player();
    SwordWeapon* sword = new SwordWeapon(5, 10, sf::Vector2f(50, 100), "content/sprites/projectiles.png");
    player_->Equip(sword);
    Monster* m = new RandomMonster(player_, 300, 300); // placeholder
    Monster* m2 = new SearchingMonster(player_, 200, 200);
    monsters_.push_back(m);
    monsters_.push_back(m2);

    gamebar_ = Gamebar(player_);
    initVariables();
    initWindow();
    dungeonMap_ = Map(window_->getSize());
}

Game::~Game()
{
    delete window_;
    delete player_;

    for (auto monster : monsters_) {
        delete monster;
    }
}

void Game::UpdateGame()
{
    Events();

    updateDt();
    manageInput();

    // Update projectiles
    updateProjectiles();
    for (auto monster : monsters_) {
        // if moved, check collision with walls
        Vector2f oldoldPos = monster->getOldPosition();
        bool monsterMoved = monster->Move(dt);
        if (monsterMoved && collidesWithWall(monster)) {
            monster->RevertMove();
            monster->SetOldPos(oldoldPos);
        }
        std::cout << std::endl;
        monster->Update(dt);
    }
    // checkCollisions(player_, Projectile::Type::EnemyProjectile);
    checkCollisions(monsters_, Projectile::Type::PlayerProjectile);
    checkAndHandleProjectileWallCollisions();
    player_->Update(dt);
    gamebar_.Update();
}
// render game frames
void Game::RenderGame()
{
    window_->clear();
    dungeonMap_.loadRoom(window_);
    player_->Render(window_);
    gamebar_.Render(window_);
    for (auto projectile : projectiles_) {
        projectile->Render(window_);
    }
    for (auto monster : monsters_) {
        monster->Render(window_);
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
            if (event_.key.code == sf::Keyboard::Space) {
                Monster* m = new RandomMonster(player_, player_->GetPos().x, player_->GetPos().y);
                monsters_.push_back(m);
                /* sf::Vector2f direction = sf::Vector2f(1, 0);
                Projectile* p = new Projectile(50, 50);
                p->SetDirection(direction);
                p->SetType(Projectile::Type::EnemyProjectile);
                projectiles_.push_back(p); */
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (event_.mouseButton.button == sf::Mouse::Button::Left) {
                auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window_));
                player_->Attack(mousePos, projectiles_);
            }
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
    videomode_ = sf::VideoMode(1280, 768);
    window_ = new sf::RenderWindow(videomode_, "Dungeon Crawler");
}

void Game::updateDt() { dt = dtClock.restart().asSeconds(); }

void Game::manageInput()
{
    bool W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool triedMoving = W || A || S || D;
    bool twoKeys = ((W || S) && (A || D));

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
    if (triedMoving) {
        if (collidesWithWall(player_)) {
            player_->RevertMove();
        }
        if (walksThroughExit(player_)) {

            float y = window_->getSize().y;
            if (player_->GetPos().y <= 0) {
                player_->setPos({ player_->GetPos().x, y - 1 });
            }
            if (player_->GetPos().y > y) {
                player_->setPos({ player_->GetPos().x, -1 });
            }
        }
    }
}

void Game::checkCollisions(std::list<Character*> characters, Projectile::Type projectileType)
{

    if (projectiles_.empty()) {
        return;
    }

    std::vector<Character*> monsterListToDelete;

    for (auto character : characters) {
        for (auto projectile : projectiles_) {
            if (projectile->GetType() == projectileType && !projectile->hasHit(character)) {
                if (Collision::PixelPerfectTest(projectile->GetSprite(), character->GetSprite())) {
                    projectile->hit(character);
                    character->TakeDamage(projectile->GetDamage());
                    if (character->IsAlive() == false) {
                        monsterListToDelete.push_back(character);
                    }
                    if (!projectile->Penetrates()) {
                        projectile->Kill();
                    }
                }
            }
        }
    }
    // Delete dead Monsters
    for (auto monster : monsterListToDelete) {
        deleteMonster(monster);
    }
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

void Game::deleteMonster(Character* m)
{
    if (monsters_.empty())
        return;

    for (auto it = monsters_.begin(); it != monsters_.end(); ++it) {
        if (*it == m) {
            monsters_.erase(it);
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
    return !dungeonMap_.GetRoom()->positionIsWalkable(character->GetBaseBoxAt(character->GetPos()));
}
bool Game::collidesWithWall(Entity* object)
{
    return !dungeonMap_.GetRoom()->positionIsWalkable(object->getSpriteBounds());
}

bool Game::walksThroughExit(Character* character)
{

    if (videomode_.width <= character->GetPos().x || videomode_.height <= character->GetPos().y || character->GetPos().x <= 0 || character->GetPos().y <= 0) {
        return true;
    }
    return false;
}
