#pragma once
#include"weapon.h"
#include <string>
class SomberWeapon : public Weapon
{
private:
    /* data */
public:
    SomberWeapon(string name);
    ~SomberWeapon();
};

SomberWeapon::SomberWeapon(string name): Weapon(name){}

SomberWeapon::~SomberWeapon()
{
}
