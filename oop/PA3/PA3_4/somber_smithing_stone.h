#pragma once
#include"smithing_stone.h"
class SomberSmithingStone:SmithingStone
{
private:
    /* data */
public:
    SomberSmithingStone(int level);
    ~SomberSmithingStone();
    void add_myamount(int amount);
    bool greater_myequal(int need);
    int get_mylevel();
};
