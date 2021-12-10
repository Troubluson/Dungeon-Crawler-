
#include "Combat/Weapons/SwordWeapon.hpp"

SwordWeapon::SwordWeapon(int damage, int range, Vector2f projectileSize, int rateOfFire, int speed, const std::string& spriteLocation)
    : Weapon(damage, range, projectileSize, rateOfFire, speed, spriteLocation)
{
    penetrates_ = true;
    sprite_.setTextureRect({ 400, 215, 10, 15 }); // placeholder
    spritehelper::SetScale(projectileSize, sprite_);
    // sets scale and origin of sprite
}
Projectile* SwordWeapon::Use(Vector2f dir, Vector2f origin)
{
    // have to rotate the projectile
    spritehelper::RotateSprite(dir, sprite_);
    spritehelper::SetOriginBottomCenter(sprite_);
    Projectile* p = new Projectile(sprite_, origin, true);
    p->SetDirection(dir);
    p->SetDamage(damage_);
    p->SetDistanceLifeSpan(range_);
    p->SetProjectileSpeed(speed_);
    return p;
}
