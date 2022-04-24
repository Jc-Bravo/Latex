#pragma once
#include"smithing_stone.h"
class SomberSmithingStone:SmithingStone
{
private:
    /* data */
public:
    SomberSmithingStone(/* args */);
    ~SomberSmithingStone();
    void add_myamount(int amount){add_amount(amount);}
    bool greater_myequal(int need){greater_equal(need);}
    int get_mylevel(){get_level();}
};

SomberSmithingStone::SomberSmithingStone(/* args */)
{
}

SomberSmithingStone::~SomberSmithingStone()
{
}
