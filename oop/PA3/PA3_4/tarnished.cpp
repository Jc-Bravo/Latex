#include"tarnished.h"

int NormalWeapon::nwnum = 0;
int SomberWeapon::swnum = 0;
//捡石头
void Tarnished::pick_up_stone(int type, int level, int number){
    if(type == 0)
        {
            //normal
            if (normal_smithing_stones[level]==NULL) {
                normal_smithing_stones[level] = new NormalSmithingStone(level);
            }
            normal_smithing_stones[level]->add_myamount(number);
        }
    else if(type == 1)
        {
            //somber
            if (somber_smithing_stones[level]==NULL) {
                somber_smithing_stones[level] = new SomberSmithingStone(level);
            }
            somber_smithing_stones[level]->add_myamount(number);
        }
}

//捡武器
void Tarnished::pick_up_weapon(int type, string name){
    if(type == 0)
        {
            //normal
            normal_weapons[NormalWeapon::nwnum] = new NormalWeapon(name);
            NormalWeapon::nwnum++;
        }
    else if(type == 1)
        {
            //somber 
            somber_weapons[SomberWeapon::swnum] = new SomberWeapon(name);
            SomberWeapon::swnum++;
        }
    return;
}


void Tarnished::upgrade_weapon(int target, string name){
/*
    先遍历是否存在weapon，不存在2，或者0，1
*/
int my_type = 2; int weaponnum = 0; 
    //遍历normal
if(NormalWeapon::nwnum != 0)
    {
        for(int i = 0; i < NormalWeapon::nwnum; i++)
        {
            string weapon_name =normal_weapons[i]->get_myname();
            if(weapon_name == name)
            {
                my_type = 0;
                weaponnum = i ; 
                break;
            }
        }
    }
    //遍历somber
if(SomberWeapon::swnum != 0)
    {
        for(int i = 0; i < SomberWeapon::swnum; i++)
        {
            string weapon_name =somber_weapons[i]->get_myname();
            if(weapon_name == name)
            {
                my_type = 1;
                weaponnum = i ; 
                break;
            }
        }        
    }
    //没找到输出
    if(my_type ==2 ) 
    {
        //没找到，错误输出
        cout<<"You don't have the right!"<<endl;
        return ;
    }
/*
    当存在武器的时候，先判断能不能强化，可以的话再强化
*/
int flag = 0;//判断是否能强化
//判断normal能不能强化
//首先判断等级，判断有没有石头/石头数量是否足够
    if(my_type == 0)
        {
            //首先判断等级
            if(target < normal_weapons[weaponnum]->get_mylevel())
             {cout<<"Stay calm!"<<endl;return;}
            //再判断数量,每级递减，使用数组记录不同等级的石头
            int up_stonelevel = 0;
            int up_stonenum[50] = {0};
            int right_level = normal_weapons[weaponnum]->get_mylevel();
            //计算需要的数量
            for(int i = right_level + 1 ; i< target+ 1; i++)
                {
                    up_stonelevel = (i -1)/3+1;
                    up_stonenum[up_stonelevel]+=2*(3-(up_stonelevel*3 - i));
                }
            //进行compare
            for(int i = 0; i<50;i++)
                {
                    if(up_stonenum[i]!=0)//需要石头，进行比较
                    {
                        if(normal_smithing_stones[i] == NULL)
                        {cout<<"Upgrade failed for lacking normal smithing stone "<<i<<endl;
                        return;}
                        if(!normal_smithing_stones[i]->greater_myequal(up_stonenum[i]))
                        //数量不够 错误输出
                            { flag = 1;
                             cout<<"Upgrade failed for lacking normal smithing stone "<<i<<endl;
                             return ;
                             }
                    }
                }
            //数量足够 开始强化
            for(int i = right_level + 1 ; i< target+ 1; i++)
            {
               up_stonelevel = (i -1)/3+1;
               up_stonenum[up_stonelevel]=2*(3-(up_stonelevel*3 - i));
               normal_smithing_stones[up_stonelevel]->add_myamount(-up_stonenum[up_stonelevel]);
               normal_weapons[weaponnum]->myupgrade();
               if(!normal_smithing_stones[up_stonelevel]->greater_myequal(1))
            //数量为0 清除
            normal_smithing_stones[up_stonelevel]->~NormalSmithingStone();
            }
        }

    else if (my_type == 1)//判断somber能不能强化
        {
            //首先判断等级
            if(target < somber_weapons[weaponnum]->get_mylevel())
             {cout<<"Stay calm!"<<endl;return;}
            //再判断数量,每级递减，使用数组记录不同等级的石头
            int up_stonelevel = 0;
            int up_stonenum[50] = {0};
            int right_level = somber_weapons[weaponnum]->get_mylevel();
            //计算需要的数量
            for(int i = right_level + 1 ; i< target+ 1; i++)
                {
                    up_stonelevel = i;
                    up_stonenum[up_stonelevel]+= 1;
                }
            //进行compare
            for(int i = 0; i<50;i++)
                {
                    if(up_stonenum[i]!=0)//需要石头，进行比较
                    {
                        if(somber_smithing_stones[i] == NULL)
                        {cout<<"Upgrade failed for lacking somber smithing stone "<<i<<endl;
                        return;}
                        if(!somber_smithing_stones[i]->greater_myequal(up_stonenum[i]))
                        //数量不够 错误输出
                            { flag = 1;
                             cout<<"Upgrade failed for lacking somber smithing stone "<<i<<endl;
                             return ;
                             }
                    }
                }
            //数量足够 开始强化
            for(int i = right_level + 1 ; i< target+ 1; i++)
            {
               up_stonelevel = i;
               up_stonenum[up_stonelevel]= 1;
               somber_smithing_stones[up_stonelevel]->add_myamount(-up_stonenum[up_stonelevel]);
               somber_weapons[weaponnum]->myupgrade();
            // chek numbers
            if(!somber_smithing_stones[up_stonelevel]->greater_myequal(1))
            //数量为0 清除
            somber_smithing_stones[up_stonelevel]->~SomberSmithingStone();
            }
        }
}
