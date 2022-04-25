#include"somber_smithing_stone.h"
 #include<iostream>
using namespace std;
SomberSmithingStone::SomberSmithingStone(int level):SmithingStone(level){}

void  SomberSmithingStone::add_myamount(int amount)
{add_amount(amount);
int level = get_level();
if(amount>0)
cout<<"Somber smithing stone "<<level<<" was added with "<<amount<<"."<<endl;
else
{
    amount = 0 - amount;
    cout<<"Somber smithing stone "<<level<<" was substracted with "<<amount<<"."<<endl;
}
}


bool SomberSmithingStone::greater_myequal(int need){return greater_equal(need);}

int SomberSmithingStone::get_mylevel(){return get_level();}

SomberSmithingStone::~SomberSmithingStone()
{
       int level = get_level();
    cout<<"Somber smithing stone "<<level<<" was destroyed."<<endl;
}