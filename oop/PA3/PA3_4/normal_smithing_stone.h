#pragma once
#include"smithing_stone.h"
class NormalSmithingStone:SmithingStone
{
private:
    /* data */
public:
    NormalSmithingStone(/* args */);
    ~NormalSmithingStone();
    void add_myamount(int amount){add_amount(amount);}
    bool greater_myequal(int need){greater_equal(need);}
    int get_mylevel(){get_level();}
};

NormalSmithingStone::NormalSmithingStone(/* args */)
{
}

NormalSmithingStone::~NormalSmithingStone()
{
}
