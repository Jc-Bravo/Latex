#include"somber_weapon.h"

string SomberWeapon::get_myname(){return get_name();}

int SomberWeapon::get_mylevel() {return get_level();}

void SomberWeapon::myupgrade()
{
    upgrade();
    int my_level = get_mylevel() - 1;
    string my_name = get_myname();
    if(my_level == 0)
       std::cout << "Somber Weapon "<< my_name<<" was upgraded to "<<my_name<<"+1"<<std::endl;
    else
        std::cout << "Somber Weapon+"<<my_level<< my_name<<" was upgraded to "<<my_name<<"+"<<my_level+1<<std::endl;
}  

SomberWeapon::SomberWeapon(string name): Weapon(name){}

SomberWeapon::~SomberWeapon()
{
}
