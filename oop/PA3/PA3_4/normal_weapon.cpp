#include"normal_weapon.h"
#include<iostream>
using namespace std;
string NormalWeapon::get_myname(){return get_name();}

int NormalWeapon::get_mylevel() {return get_level();}

void NormalWeapon::myupgrade()
{
        upgrade();
        int my_level = get_mylevel() - 1;
        string my_name = get_myname();
        if(my_level == 0)
            std::cout << "Normal weapon "<< my_name<<" was upgraded to "<<my_name<<"+1"<<"."<<std::endl;
        else
            std::cout << "Normal weapon "<<my_name<<"+"<<my_level<<" was upgraded to "<<my_name<<"+"<<my_level+1<<"."<<std::endl;
}  

NormalWeapon::NormalWeapon(string name): Weapon(name){}

NormalWeapon::~NormalWeapon()
{
    string name = get_myname();
    int level = get_mylevel();
    if(level==0)
    cout<<"Normal weapon "<<name<<" was destroyed."<<endl;
    else
    cout<<"Normal weapon "<<name<<"+"<<level<<" was destroyed."<<endl;
 
}
