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
    string get_myname(){
        return get_name();
    }
    int get_mylevel() 
    {
        return get_level();
    }
    void myupgrade()
    {
        upgrade();
    }
};

SomberWeapon::SomberWeapon(string name): Weapon(name){}

SomberWeapon::~SomberWeapon()
{
}
