#pragma once
#include"weapon.h"
#include <string>
#include <iostream>
class NormalWeapon : public Weapon
{
private:
    /* data */
public:
    static int nwnum;
    NormalWeapon(string name);
    ~NormalWeapon();
    string get_myname();
    int get_mylevel();
    void myupgrade();
};

