#include"bianliang.h"

void toubi()//投币
{
    int i = 0;
    int money[100]={0};//初始化0用数组储存货币
    printf("请投币（-1结尾）：");
    for(i = 0; money[i-1] != -1; i++)//输入硬币
    {
        scanf("%d",&money[i]);
    }//for
    for(i = 0; money[i] != -1; i++)
    {
        summoney = summoney + money[i];
    }//for
    total = summoney;//记录总额
    bianse();//当按下键的时候变色
}//toubi
