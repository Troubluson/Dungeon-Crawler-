
#include "Combat/Weapons/SwordWeapon.hpp"
#include <cmath>

SwordWeapon::SwordWeapon(int damage, int range, Vector2f projectileSize, int rateOfFire, const std::string& spriteLocation)
    : Weapon(damage, range, projectileSize, rateOfFire, spriteLocation)
{
    penetrates_ = true;
    sprite_.setTextureRect({ 400, 215, 10, 15 });
    sprite::SetScale(projectileSize, sprite_);
    // sets scale and origin of sprite
}
list<Projectile*> SwordWeapon::Use(Vector2f dir, Vector2f origin)
{
    // have to rotate the projectile
    sprite::RotateSprite(dir, sprite_);
    auto p = new Projectile(sprite_, origin, true);
    p->SetDirection(dir);
    p->SetDamage(damage_);
    p->SetDistanceLifeSpan(range_);
    p->SetProjectileSpeed(1000);
    p->SetType(Projectile::Type::PlayerProjectile); // should maybe be set in players attack function instead
    return list<Projectile*> { p };
}
