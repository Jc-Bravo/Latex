#pragma once
#include"weapon.h"
#include <string>
#include<iostream>
class SomberWeapon : public Weapon
{
private:
    /* data */
public:
    static int swnum;
    SomberWeapon(string name);
    ~SomberWeapon();
    string get_myname();
    int get_mylevel() ;
    void myupgrade();
};
