#pragma once
#include<string.h>
#include<iostream>
#include "normal_smithing_stone.h"
#include "normal_weapon.h"
#include "somber_smithing_stone.h"
#include "somber_weapon.h"

#define MAX_STONES 50
#define MAX_WEAPONS 1000
using namespace std;
class Tarnished
{
private:
    NormalWeapon *normal_weapons[MAX_WEAPONS] ;
    SomberWeapon *somber_weapons[MAX_WEAPONS] ;
    NormalSmithingStone *normal_smithing_stones[MAX_STONES];
    SomberSmithingStone *somber_smithing_stones[MAX_STONES] ;

public:
    Tarnished(){};
    ~Tarnished(){};
    void pick_up_stone(int type, int level, int number);
    void pick_up_weapon(int type, string name);
    void upgrade_weapon(int target, string name);
};






// void Tarnished::upgrade_weapon(int target, string name){
//     //bianli weapon,get the weapon's name
//     int my_type = 2;
//     int WeapomNum = 0;
//     for(int i =0; i<MAX_WEAPONS; i++)
//         {
//             if (normal_weapons[i]!=NULL){
//                 string weapon_name =normal_weapons[i]->get_myname();
//                 if(weapon_name==name)
//                 {
//                     my_type = 0;
//                     WeapomNum = i;
//                     break;
//                 }
//             }
//         }
//     if (my_type == 2)
//     for(int i =0; i<MAX_WEAPONS; i++)
//         {
//             if (normal_weapons[i]!=NULL){
//                 if(somber_weapons[i]->get_myname()==name)
//                 {
//                     my_type = 1;
//                     WeapomNum = i;
//                     break;
//                 }
//             }
//         }
//     //error output
//     if(my_type == 2)
//         {
//             cout<<"You don't have the right!"<<endl;
//             return;
//         }

//     else if(my_type==0)
// // 0 -> 1 two so 0,1,2 use 1th
// // target means (target - 1)/3 &
//     //normal upgrade
//         {
//             if(target < normal_weapons[WeapomNum]->get_mylevel())
//             {cout<<"Stay calm!"<<endl;return;}
//             else{
//             //upgreade
//             //check numbers
//                 int up_stonelevel = 0 ;
//                 int up_stonenum[50]= {0};
//                 int level = normal_weapons[WeapomNum]->get_mylevel();
//                 for(int i = level + 1; i < target + 1; i++)
//                 {
//                     up_stonelevel = (i -1)/3+1;
//                     up_stonenum[up_stonelevel]+=2*(3-(up_stonelevel*3 - i));
//                 }
//                 int flag = 0;
//                 for(int i = 0; i<50;i++)
//                 {
//                     if(up_stonenum[i]!=0)//需要石头，进行比较
//                     {
//                         if(normal_smithing_stones[i] == NULL)
//                         {cout<<"Stay calm!"<<endl;return;}
//                         if(!normal_smithing_stones[i]->greater_myequal(up_stonenum[i]))
//                             flag = 1;
//                     }
//                 }
//                 if(flag == 0)//can upgrade
//                 {
//                     for(int i = 0; i<50;i++)
//                 {
//                     if(up_stonenum[i]!=0)//it's ok and minus
//                     {
//                         normal_smithing_stones[i]->add_myamount(-up_stonenum[i]);
//                         if(up_stonenum[i]==2)
//                         normal_weapons[WeapomNum]->myupgrade();
//                         else if(up_stonenum[i]==4)
//                         normal_weapons[WeapomNum]->myupgrade();
//                         else if(up_stonenum[i]==6)//check two or one
//                             {
//                                 if(target%3 == 2 )
//                                 {normal_weapons[WeapomNum]->myupgrade();
//                                 normal_weapons[WeapomNum]->myupgrade();}
//                                 else normal_weapons[WeapomNum]->myupgrade();
//                             }
//                         else if(up_stonenum[i]==8)
//                         {normal_weapons[WeapomNum]->myupgrade();
//                         normal_weapons[WeapomNum]->myupgrade();}
//                         else if(up_stonenum[i]==10)
//                         {normal_weapons[WeapomNum]->myupgrade();
//                         normal_weapons[WeapomNum]->myupgrade();}
//                         else if(up_stonenum[i]==12)
//                         {normal_weapons[WeapomNum]->myupgrade();
//                         normal_weapons[WeapomNum]->myupgrade();
//                         normal_weapons[WeapomNum]->myupgrade();}
//                     }
//                 }

//                     return;
//                 }
//                 else if(flag == 1)//can't upgrade
//                 {
//                     cout<<"Upgrade failed for lacking <xxx>."<<endl;
//                     return ;

//                 }
// }
//         }

// // smithing weapon upgreade
//     else if(my_type == 1)
//     {
//             if(target-1 == normal_weapons[WeapomNum]->get_mylevel())
//             //upgreade
//                 {
//                     int up_level = (target-1)/3 +1;
//                     int up_need = 2*(target - up_level*3);
//                     if(somber_smithing_stones[up_level]->greater_myequal(up_need))
//                         {
//                             somber_smithing_stones[up_level]->add_myamount(-up_need);
//                             somber_weapons[WeapomNum]->myupgrade();
//                             return;
//                         }
//                     else {
//                         cout<<"Upgrade failed for lacking <xxx>."<<endl;
//                         return ;
//                     }
//                 }
//             else {cout<<"Stay calm!"<<endl;return;}
//     }

//     //Todo: check if is zero,if is delete it

// }
