#include"normal_weapon.h"

string NormalWeapon::get_myname(){return get_name();}

int NormalWeapon::get_mylevel() {return get_level();}

void NormalWeapon::myupgrade()
{
        upgrade();
        int my_level = get_mylevel() - 1;
        string my_name = get_myname();
        if(my_level == 0)
            std::cout << "Normal Weapon "<< my_name<<" was upgraded to "<<my_name<<"+1"<<std::endl;
        else
            std::cout << "Normal Weapon+"<<my_level<< my_name<<" was upgraded to "<<my_name<<"+"<<my_level+1<<std::endl;
}  

NormalWeapon::NormalWeapon(string name): Weapon(name){}

NormalWeapon::~NormalWeapon()
{
}
