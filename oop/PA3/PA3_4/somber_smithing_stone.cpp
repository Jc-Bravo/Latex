#include"somber_smithing_stone.h"
 
SomberSmithingStone::SomberSmithingStone(int level):SmithingStone(level){}

void  SomberSmithingStone::add_myamount(int amount){add_amount(amount);}

bool SomberSmithingStone::greater_myequal(int need){return greater_equal(need);}

int SomberSmithingStone::get_mylevel(){return get_level();}

SomberSmithingStone::~SomberSmithingStone()
{
}