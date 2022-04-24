#pragma once
#include<string.h>
#include "normal_smithing_stone.h"
#include "normal_weapon.h"
#include "somber_smithing_stone.h"
#include "somber_weapon.h"

#define MAX_STONES 50
#define MAX_WEAPONS 1000

class Tarnished
{
private:
    NormalWeapon *normal_weapons[MAX_WEAPONS];
    SomberWeapon *somber_weapons[MAX_WEAPONS];
    NormalSmithingStone *normal_smithing_stones[MAX_STONES];
    SomberSmithingStone *somber_smithing_stones[MAX_STONES];

public:
    int Weapon_number = 0;
    Tarnished(){};
    ~Tarnished(){};
    void pick_up_stone(int type, int level, int number);
    void pick_up_weapon(int type, string name);
    void upgrade_weapon(int target, string name);
};

void Tarnished::pick_up_stone(int type, int level, int number){
    if(type == 0)
        {
            //normal
            normal_smithing_stones[level]->add_myamount(number);
        }
    else if(type == 1)
        {
            // Todo : smithing
            somber_smithing_stones[level]->add_myamount(number);

        }
}
void Tarnished::pick_up_weapon(int type, string name){
    if(type == 0)
        {
            //Todo normal
            normal_weapons[Weapon_number] = new NormalWeapon(name);
        }
    else if(type == 1)
        {
            //Todo smithing 
            somber_weapons[Weapon_number] = new SomberWeapon(name);
        }  
    Weapon_number++;
    return;
}

void Tarnished::upgrade_weapon(int target, string name){
    //bianli weapon,get the weapon's name
    int my_type = 2;
    int WeapomNum = 0;
    for(int i =0; i<MAX_WEAPONS; i++)
        {
            if(normal_weapons[i]->get_myname()==name)
            {
                my_type = 0;
                WeapomNum = i;
                break;
            }

        }
    if (my_type == 2)
    for(int i =0; i<MAX_WEAPONS; i++)
        {
            if(somber_weapons[i]->get_myname()==name)
            {
                my_type = 1;
                WeapomNum = i;
                break;
            }

        } 
    //error output
    if(my_type == 2)
        {
            cout<<"You don't have the right!"<<endl;
            return;
        }

    else if(my_type==0)
    //Todo normal upgrade
        {
            if(target-1 == normal_weapons[WeapomNum]->get_mylevel())
            //upgreade
                {
                    int up_level = target/3 +1; 
                    int up_need = 2*(target - up_level*3);
                    if(normal_smithing_stones[up_level]->greater_myequal(up_need))
                        {
                            normal_smithing_stones[up_level]->add_myamount(-up_need);
                            normal_weapons[WeapomNum]->myupgrade();
                            return;
                        }
                    else {
                        cout<<"Upgrade failed for lacking <xxx>."<<endl;
                        return ;
                    }
                }
            else {cout<<"Stay calm!"<<endl;return;}
        }

// smithing weapon upgreade
    else if(my_type == 1)
    {
            if(target-1 == normal_weapons[WeapomNum]->get_mylevel())
            //upgreade
                {
                    int up_level = target; 
                    int up_need = target;
                    if(normal_smithing_stones[up_level]->greater_myequal(up_need))
                        {
                            normal_smithing_stones[up_level]->add_myamount(-up_need);
                            normal_weapons[WeapomNum]->myupgrade();
                            return;
                        }
                    else {
                        cout<<"Upgrade failed for lacking <xxx>."<<endl;
                        return ;
                    }
                }
            else {cout<<"Stay calm!"<<endl;return;}
    }

}