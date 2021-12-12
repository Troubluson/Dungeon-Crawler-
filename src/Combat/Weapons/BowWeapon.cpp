
#include "Combat/Weapons/BowWeapon.hpp"

BowWeapon::BowWeapon(int damage, int range, int rateOfFire, float projectileSpeed, Vector2f projectileSize, const std::string& spriteLocation)
    : Weapon(damage, range, rateOfFire, projectileSpeed, projectileSize, spriteLocation)
{
    penetrates_ = false;
    sprite_.setTextureRect({ 400, 215, 10, 15 }); // placeholder
    spritehelper::SetScale(projectileSize, sprite_);
    // sets scale and origin of sprite
}

ProjectileUP BowWeapon::Use(Vector2f dir, Vector2f origin)
{
    // have to rotate the projectile
    spritehelper::RotateSprite(dir, sprite_);
    spritehelper::SetOriginBottomCenter(sprite_);
    ProjectileUP p(new Projectile(sprite_, origin, true));
    p->SetDirection(dir);
    p->SetDamage(damage_);
    p->SetDistanceLifeSpan(range_);
    p->SetProjectileSpeed(projectileSpeed_);
    return p;
}
