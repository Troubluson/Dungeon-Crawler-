#include "roomInstance.hpp"

RoomInstance::RoomInstance(sf::Vector2u window_size)
{
    gridLen_ = 20;
    setUpRoomInstance(window_size);
}

void RoomInstance::Render(sf::RenderTarget* target)
{
    target->draw(roomBackground);
}

void RoomInstance::setUpRoomInstance(sf::Vector2u window_size)
{
    exitPosition = sf::Vector2i(1, 0);
    playerPosition = sf::Vector2i(gridLen_ - 4, gridLen_ - 4);
    setTiles(window_size);
}

void RoomInstance::setTiles(sf::Vector2u window_size)
{
    tileVector_.clear();
    int n = 0;
    for (int i = 0; i < gridLen_; i++) {
        std::vector<RoomTile*> row;
        int k = 0;
        for (int j = 0; j < gridLen_; j++) {
            if (i == 0) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallleft.png", k, n, false, false));
                } else if (j == 19) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomleft.png", k, n, false, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/toppartofwall1.png", k, n, false, false));
                }
            } else if (i == 1 && j != 0 && j != 19) {
                row.push_back(new RoomTile("content/sprites/walls/wallfront1.png", k, n, false, false));
            } else if (i == 11) {
                if (j == 0) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallright.png", k, n, false, false));
                } else if (j == 19) {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottomright.png", k, n, false, false));
                } else {
                    row.push_back(new RoomTile("content/sprites/walls/topwallbottom.png", k, n, false, false));
                }
            } else if (i != 0 && j == 0) {
                row.push_back(new RoomTile("content/sprites/walls/topwallLEFTSIDE.png", k, n, false, false));
            } else if (i != 0 && j == 19) {
                row.push_back(new RoomTile("content/sprites/walls/topwallRIGHTSIDE.png", k, n, false, false));
            } else {
                row.push_back(new RoomTile("content/sprites/floors/tile1.png", k, n, true, false));
            }

            k += 64;
        }
        n += 64;
        tileVector_.push_back(row);
    }
    renderSpriteBackground(window_size);
}

void RoomInstance::renderSpriteBackground(sf::Vector2u window_size)
{
    int x = window_size.x / 64;
    std::cout << x << std::endl;
    roomTexture.create(window_size.x, window_size.y);
    for (int i = 0; i < this->gridLen_; i++) {
        for (int j = 0; j < this->gridLen_; j++) {
            roomTexture.draw(this->tileVector_[i][j]->tileSprite);
        }
    }
    roomTexture.display();
    roomBackground.setTexture(roomTexture.getTexture());
}
