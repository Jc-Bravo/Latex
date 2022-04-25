#pragma once
#include"smithing_stone.h"
class NormalSmithingStone:SmithingStone
{
private:
    /* data */
public:
    NormalSmithingStone(int level);
    ~NormalSmithingStone();
    void add_myamount(int amount);
    bool greater_myequal(int need);
    int get_mylevel();
};




