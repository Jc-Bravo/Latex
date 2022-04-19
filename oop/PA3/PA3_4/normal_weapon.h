#pragma once
#include"weapon.h"
#include <string>
class NormalWeapon : public Weapon
{
private:
    /* data */
public:
    using Weapon::Weapon; 
    ~NormalWeapon();
};


NormalWeapon::~NormalWeapon()
{
}
