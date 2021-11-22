
#include "SwordWeapon.hpp"

SwordWeapon::SwordWeapon(int damage, int range, Vector2f projectileSize, const std::string& spriteLocation)
    : Weapon(damage, range, projectileSize, spriteLocation)
{
    penetrates_ = true;
}
list<Projectile*> SwordWeapon::Use(Vector2f dir, Vector2f origin)
{
    auto p = new Projectile(sprite_, origin, true);
    p->SetDirection(dir);
    p->SetDamage(damage_);
    p->SetDistanceLifeSpan(range_);
    p->SetProjectileSpeed(200);
    p->SetType(Projectile::Type::PlayerProjectile); // should maybe be set in players attack function instead
    return list<Projectile*> { p };
}
