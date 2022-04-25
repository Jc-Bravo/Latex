#include"normal_smithing_stone.h"
#include<iostream>
using namespace std;

NormalSmithingStone::NormalSmithingStone(int level):SmithingStone(level){}

void  NormalSmithingStone::add_myamount(int amount)
{
    add_amount(amount);
    int level = get_level();
    if(amount>0)
    cout<<"Normal smithing stone "<<level<<" was added with "<<amount<<"."<<endl;
else
{
    amount = 0 - amount;
    cout<<"Normal smithing stone "<<level<<" was substracted with "<<amount<<"."<<endl;
}
}

bool NormalSmithingStone::greater_myequal(int need){return greater_equal(need);}

int NormalSmithingStone::get_mylevel(){return get_level();}

NormalSmithingStone::~NormalSmithingStone()
{
    int level = get_level();
    cout<<"Normal smithing stone "<<level<<" was destroyed."<<endl;
}