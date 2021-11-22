
#include "SwordWeapon.hpp"
#include <cmath>
#define PI 3.14159265

SwordWeapon::SwordWeapon(int damage, int range, Vector2f projectileSize, const std::string& spriteLocation)
    : Weapon(damage, range, projectileSize, spriteLocation)
{
    penetrates_ = true;
    sprite_.setTextureRect({ 400, 215, 10, 15 });
    // sets scale and origin of sprite
    auto bounds = sprite_.getLocalBounds();
    auto scaleX = projectileSize.x / bounds.width;
    auto scaleY = projectileSize.y / bounds.height;
    sprite_.setScale(0.9 * scaleX, scaleY);
    sprite_.setOrigin(bounds.width / 2, bounds.height);
}
list<Projectile*> SwordWeapon::Use(Vector2f dir, Vector2f origin)
{
    // have to rotate the projectile
    auto angle = atan2(dir.y, dir.x) * 180 / PI + 90;
    sprite_.setRotation(angle);
    auto p = new Projectile(sprite_, origin, true);
    p->SetDirection(dir);
    p->SetDamage(damage_);
    p->SetDistanceLifeSpan(range_);
    p->SetProjectileSpeed(1000);
    p->SetType(Projectile::Type::PlayerProjectile); // should maybe be set in players attack function instead
    return list<Projectile*> { p };
}
