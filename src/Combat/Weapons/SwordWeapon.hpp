
#include "Weapon.hpp";

class SwordWeapon : public Weapon {
 private:
  /* data */
 public:
  SwordWeapon(/* args */) {}
  virtual void Use(direction dir);
  ~SwordWeapon() {}
};