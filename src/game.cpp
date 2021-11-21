#include "game.hpp"

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
    Monster* m = new Monster(300, 300); // placeholder
    monsterVector_.push_back(m);
    initVariables();
    initWindow();
}

Game::~Game()
{
    delete window_;
    delete player_;
    for (auto monster : monsterVector_) {
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
    for (auto monster : monsterVector_) {
        monster->Update();
        monster->Move(dt);
    }
    // checkCollisions(player_, Projectile::Type::EnemyProjectile);
    checkCollisions(monsterVector_, Projectile::Type::PlayerProjectile);
    checkWallCollisions();
    player_->Update();
}
// render game frames
void Game::RenderGame()
{
    window_->clear();
    room.Render(window_);
    player_->Render(window_);
    for (auto projectile : projectileVector) {
        projectile->Render(window_);
    }
    for (auto monster : monsterVector_) {
        monster->Render(window_);
    }
    window_->display();
}
// Keeps the game running when window is open
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
                Monster* m = new Monster(player_->GetPos().x, player_->GetPos().y);
                monsterVector_.push_back(m);
                /* sf::Vector2f direction = sf::Vector2f(1, 0);
                Projectile* p = new Projectile(50, 50);
                p->SetDirection(direction);
                p->SetType(Projectile::Type::EnemyProjectile);
                projectileVector.push_back(p); */
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (event_.mouseButton.button == sf::Mouse::Button::Left) {
                int offset = 20 * 3;
                sf::Vector2i playerPos = player_->GetPos();
                sf::Vector2f direction = sf::Vector2f(
                    static_cast<float>(sf::Mouse::getPosition(*window_).x) - 20 - playerPos.x - offset,
                    static_cast<float>(sf::Mouse::getPosition(*window_).y) - 20 - playerPos.y - offset);

                sf::Vector2i projectilePos = playerPos + sf::Vector2i(offset, offset);

                Projectile* p = new Projectile(projectilePos, PLACEHOLDER_PROJ_SIZE);
                // could maybe be changed to be less lines
                p->SetType(Projectile::PlayerProjectile);
                p->SetDamage(PLACEHOLDER_PROJ_DMG);
                p->SetProjectileSpeed(PLACEHOLDER_PROJ_SPEED);
                p->SetDirection(direction);
                p->SetTimeLifeSpan(PLACEHOLDER_PROJ_LS);
                p->SetDistanceLifeSpan(PLACEHOLDER_PROJ_DIST);

                projectileVector.push_back(p);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player_->MoveLeft(dt);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player_->MoveRight(dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player_->MoveUp(dt);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player_->MoveDown(dt);
    }
}

void Game::checkCollisions(std::vector<Character*> characterVector, Projectile::Type type)
{
    if (projectileVector.size() <= 0) {
        return;
    }

    std::vector<int> projectileListToDelete;
    std::vector<int> monsterListToDelete;

    int i = 0;
    for (auto character : characterVector) {
        int j = 0;
        for (auto projectile : projectileVector) {
            if (projectile->GetType() == type) {
                if (projectile->GetSprite().getGlobalBounds().intersects(character->GetSprite().getGlobalBounds())) {
                    std::cout << "Crash" << std::endl;
                    character->TakeDamage(projectile->GetDamage());
                    if (character->IsAlive() == false) {
                        monsterListToDelete.push_back(i);
                    }
                    projectileListToDelete.push_back(j);
                }
            }
            j += 1;
        }
        i += 1;
    }

    // Delete colliding projectiles
    for (auto it : projectileListToDelete) {
        projectileVector[it] = projectileVector.back();
        projectileVector.pop_back();
        break;
    }

    // Delete dead Monsters
    for (auto it : monsterListToDelete) {
        monsterVector_[it] = monsterVector_.back();
        monsterVector_.pop_back();
        break;
    }
}

void Game::checkWallCollisions()
{
    if (projectileVector.size() <= 0) {
        return;
    }

    std::vector<int> projectileListToDelete;

    for (auto row : room.tileVector_) {
        for (auto tile : row) {
            if (tile->isWalkable == false) {
                int i = 0;
                for (auto projectile : projectileVector) {
                    if (projectile->GetSprite().getGlobalBounds().intersects(tile->tileSprite.getGlobalBounds())) {
                        std::cout << "Crash" << std::endl;
                        projectileListToDelete.push_back(i);
                    }
                    i += 1;
                }
            }
        }
    }

    for (auto it : projectileListToDelete) {
        projectileVector[it] = projectileVector.back();
        projectileVector.pop_back();
        break;
    }
}

void Game::deleteProjectile(Projectile* p)
{
    if (projectileVector.size() <= 0) {
        return;
    }

    int i = 0;
    for (auto it : projectileVector) {
        if (it == p) {
            projectileVector.erase(projectileVector.begin() + i);
            return;
        }
        i += 1;
    }
}

void Game::deleteMonster(Monster* m)
{
    if (monsterVector_.size() <= 0) {
        return;
    }

    int i = 0;
    for (auto it : monsterVector_) {
        if (it == m) {
            monsterVector_.erase(monsterVector_.begin() + i);
            return;
        }
        i += 1;
    }
}

void Game::updateProjectiles()
{
    for (auto projectile : projectileVector) {
        if (projectile->IsAlive() == false) {
            deleteProjectile(projectile);
        }
        projectile->Update(dt);
    }
}