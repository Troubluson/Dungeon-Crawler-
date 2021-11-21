
#include "SwordWeapon.hpp"

SwordWeapon::SwordWeapon(int damage, int range, Vector2f projectileSize, const std::string& spriteLocation)
    : Weapon(damage, range, projectileSize, spriteLocation)
{
    penetrates_ = true;
}
void SwordWeapon::Use(Vector2f)
{
    auto p = new Projectile(owner_->GetPos(), projectileSize_, true);
    p->SetSprite(sprite_);
}
