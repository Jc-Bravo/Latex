#pragma once
#include"weapon.h"
#include <string>
class NormalWeapon : public Weapon
{
private:
    /* data */
public:
    NormalWeapon(string name):Weapon(name){}
    ~NormalWeapon();
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


NormalWeapon::~NormalWeapon()
{
}
