#include"normal_smithing_stone.h"
 
NormalSmithingStone::NormalSmithingStone(int level):SmithingStone(level){}

void  NormalSmithingStone::add_myamount(int amount){add_amount(amount);}

bool NormalSmithingStone::greater_myequal(int need){return greater_equal(need);}

int NormalSmithingStone::get_mylevel(){return get_level();}

NormalSmithingStone::~NormalSmithingStone()
{
}