
#include "Combat/Weapons/SwordWeapon.hpp"

SwordWeapon::SwordWeapon(int damage, int range, int rateOfFire, float projectileSpeed, Vector2f projectileSize, const std::string& spriteLocation)
    : Weapon(damage, range, rateOfFire, projectileSpeed, projectileSize, spriteLocation)
{
    penetrates_ = true;
    spritehelper::SetScale(projectileSize, sprite_);
}

ProjectileUP SwordWeapon::Use(Vector2f dir, Vector2f origin)
{
    std::cout << currentDamage_ << std::endl;
    // have to rotate the projectile
    spritehelper::RotateSprite(dir, sprite_);
    spritehelper::SetOriginBottomCenter(sprite_);
    ProjectileUP p(new Projectile(sprite_, origin, true));
    p->SetDirection(dir);
    p->SetDamage(currentDamage_);
    p->SetDistanceLifeSpan(range_);
    p->SetProjectileSpeed(projectileSpeed_);
    return p;
}
