#include "game.hpp"

Game::Game()
    : player_(new Player())
    , monster_(new Monster(200, 200))
{
    initVariables();
    initWindow();
}

Game::~Game()
{
    delete window_;
    delete monster_;
    delete player_;
}

void Game::UpdateGame()
{
    Events();

    updateDt();
    manageInput();

    // Update projectiles
    updateProjectiles();
    checkCollisions(player_, Projectile::Type::EnemyProjectile);
    checkCollisions(monster_, Projectile::Type::PlayerProjectile);
    player_->Update();
    monster_->Update();
}
// render game frames
void Game::RenderGame()
{
    window_->clear();
    room.Render(window_);
    for (auto it : projectileVector) {
        it->Render(window_);
    }
    player_->Render(window_);
    monster_->Render(window_);
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
                sf::Vector2f direction = sf::Vector2f(1, 0);
                Projectile* p = new Projectile(50, 50);
                p->SetDirection(direction);
                p->SetType(Projectile::Type::EnemyProjectile);
                projectileVector.push_back(p);
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (event_.mouseButton.button == sf::Mouse::Button::Left) {
                sf::Vector2f direction = sf::Vector2f(
                    static_cast<float>(sf::Mouse::getPosition(*window_).x) - player_->GetPosition().x,
                    static_cast<float>(sf::Mouse::getPosition(*window_).y) - player_->GetPosition().y);
                int offset = 20 * 3;
                Projectile* p = new Projectile(player_->GetPosition().x + offset, player_->GetPosition().y + offset);
                p->SetType(Projectile::PlayerProjectile);
                p->SetDamage(5);
                p->SetProjectileSpeed(1000);
                p->SetDirection(direction);
                p->SetTimeLifeSpan(2);
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
    monster_->Move(dt);
}

void Game::checkCollisions(Entity* e, Projectile::Type type)
{
    if (projectileVector.size() <= 0) {
        return;
    }

    std::vector<int> listToDelete;
    int i = 0;
    for (auto projectile : projectileVector) {
        if (projectile->GetSprite().getGlobalBounds().intersects(
                e->GetSprite().getGlobalBounds())) {
            if (projectile->GetType() == type) {
                std::cout << "Crash" << std::endl;
                listToDelete.push_back(i);
            }
        }
        i += 1;
    }
    for (auto it : listToDelete) {
        projectileVector.erase(projectileVector.begin() + it);
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

void Game::updateProjectiles()
{
    for (auto it : projectileVector) {
        if (it->GetTimeExisted() >= it->GetTimeLifeSpan()) {
            deleteProjectile(it);
        }
        it->Update(dt);
    }
}