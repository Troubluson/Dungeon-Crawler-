
#include "Combat/PowerUps/PowerUp.hpp"
#include "Direction.hpp"

using namespace std;
using namespace sf;

class Weapon {
protected:
    int damage_;
    int range_;
    const int maxPowerUps = 3;
    int getPowerUpCount();
    sf::Sprite sprite_;
    vector<PowerUp*> powerUps_;

public:
    Weapon(int damage, int range, Sprite sprite,
        vector<PowerUp*> powerUps = vector<PowerUp*>())
        : damage_(damage)
        , range_(range)
        , sprite_(sprite)
        , powerUps_(powerUps) {};

    virtual void Use(direction dir = direction::E) = 0;
    virtual void Animate() = 0;
    void AddPowerUp(PowerUp* up);
    ~Weapon();
};
