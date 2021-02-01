#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


struct node//商品属性
{
    char name[20];//商品名字
    int price;//价格
    int tag;//购买标记

}goods[10];//采用顺序存储商品数据

/*全局变量声明------------------------------------------*/
int flag = 1;//选择
int summoney = 0;//余额
int total = 0;//总额
int cunbi = 0;//交易货币
char password[6]={"123456"};
/*-----------------------------------------------------*/

/*函数声明-----------------------------------------------*/
void caidan();//主菜单
void toubi();//投币模式
void InitGoods();//初始化商品
void InitTag();//初始化商品选择情况
void xianshiping();//主页面
void xianshiping2();//选择商品时的显示窗口
void goumai();//购买模式
void goumaichenggong();//购买成功显示窗口
void guanliyuan();//管理员入口
void guanliyuanmoshi();//进入管理员模式
int passwordyanzheng(char *pass);//验证密码
void guanliyuancaidan();//显示管理员菜单
void chaxuhuobi();//查询机内存币
void genggaishangping();//更改商品信息
void quxiaojiaoyi();//取消交易
void xianshi_gengai();//更改显示屏
void chaxunhuobi();//查询存币
void bianse();//变色
/*-------------------------------------------------------*/

//主菜单---------------------------------------------------------------------------------
void caidan()//菜单选项
{
    scanf("%d",&flag);
    switch (flag)
    {
        case 1:
            toubi();//投币
            break;
        case 2:
            goumai();//购买
            break;
        case 3:
            guanliyuan();//管理员
            break;
        case -1 :
            quxiaojiaoyi();//取消购买
            break;
        default :
            break;
    }
}
//初始化---------------------------------------------------------------------------------
void InitTag()//初始化商品购买情况
{
    int i;
    for(i = 0; i < 10; i++)
    {
        goods[i].tag = 0;
    }
}//inittag

void InitGoods()//初始化商品
{
    char a[] = "Pure";
    strcpy(goods[0].name,a);
    goods[0].price = 3;

    char b[] = "soda";
    strcpy(goods[1].name,b);
    goods[1].price = 3;

    char c[] = "Cola";
    strcpy(goods[2].name,c);
    goods[2].price = 4;

    char d[] = "Milk";
    strcpy(goods[3].name,d);
    goods[3].price = 4;

    char e[] = "Beer";
    strcpy(goods[4].name,e);
    goods[4].price = 5;

    char f[] = "Juice";
    strcpy(goods[5].name,f);
    goods[5].price = 4;

    char g[] = "Sprite";
    strcpy(goods[6].name,g);
    goods[6].price = 3;

    char h[] = "Red Tea";
    strcpy(goods[7].name,h);
    goods[7].price = 2;

    char j[] = "Green Tea";
    strcpy(goods[8].name,j);
    goods[8].price = 2;

    char k[] = "Red Bull";
    strcpy(goods[9].name,k);
    goods[9].price = 8;

    InitTag();//清空商品购买情况
}//Initgoods
//---------------------------------------------------------------------------------------


//投币------------------------------------------------------------------------------------
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


//购买商品----------------------------------------------------------------------------
void goumai()//购买商品
{
    bianse();//随机变色-------------------------------------------------------------------------变色
    int num;//选择编号
    int money = summoney;//记录原本余额

    system("cls");
    xianshiping2();
    printf("输入商品编号(-1确认)：");
    scanf("%d",&num);
    bianse();//随机变色---------------------------------------------------------------------变色
    while(num != -1)
    {
        if(num > 0 && num <= 10)//仅有1-10编号得商品
        {
            summoney = summoney - goods[num - 1].price;//余额变化
            goods[num -1].tag++;//选择
        }
        system("cls");
        xianshiping2();
        scanf("%d",&num);
        bianse();//随机变色------------------------------------------------------------变色
        if(num == 11)//确认购买
        {
            if(summoney >= 0)//余额足够购买时
            {
                goumaichenggong();//------------------------------购买成功
                return;//退出购买模式

            }else printf("购买失败 货币不足\n"),system("pause");//--购买失败

        }else if(num == 12)//重新选择
        {
            InitTag();
            summoney = money;
        }else if(num == -1)//取消选择
        {
            InitTag();
            summoney = money;
        }

    }//while
    system("color 07");
}//goumai

void goumaichenggong()//购买成功
{
    int i;
    printf("Total: %dyuan, change: %dyuan\n",total, summoney);
    for(i = 0; i < 10; i++)//显示购买商品
    {
        if(goods[i].tag != 0)
        {
            printf("%s:%d\n",goods[i].name,goods[i].tag);
        }
    }
    InitTag();//清空选择；
    total = summoney = 0;//清空
    system("pause");
}
//取消交易-----------------------------------------------------------------------------
void quxiaojiaoyi()//取消交易
{
    if(summoney <= 0)return;
    summoney = total = 0;//清空
    printf("感谢使用...货币已退还\n");
    system("pause");
}//quxiaojiaoyi

//管理员模式----------------------------------------------------------------------------
void guanliyuan()
{
    int conut;
    int flag2 = 1;
    char password_enter[6];
    while(flag2 == 1)//输入密码，进入管理员模式
    {
        system("cls");//清屏
        xianshiping();//显示显示屏界面
        printf("输入6位密码：");

        getchar();//过去回车
        for(conut = 0; conut < 6 ; conut++)//密码输入
        {
            password_enter[conut] = getchar();
        }//for
        getchar();//获取回车键
        fflush(stdin);//清楚超出密码长度的数字
        if(passwordyanzheng(password_enter) == 1)//密码检验
        {
            guanliyuanmoshi();                               //进入管理员模式
            return;

        }else {//提示

            for(conut = 0; conut < 6; conut++)password_enter[conut] = '0';//输入的密码清零
            printf("密码错误！！!\n");
            printf("[1]:重新输入   [2]:退出");
        }//if
        scanf("%d",&flag2);//输入选择
    }//while
}//guanliyuan

int passwordyanzheng(char *pass)//验证密码
{
    int conut;//计数器
    for(conut = 0; conut < 6; conut ++)//暴力搜索
    {
        if(pass[conut] != password[conut])return 0;//如果密码不匹配则返回0
    }
    return 1;//如果密码匹配则返回1
}

void guanliyuanmoshi()//进入管理员模式------------------
{
    system("color 0c");
    int flag3 = 0;//选择键
    while(flag3 != -1)
    {
        system("cls");
        guanliyuancaidan();//更新显示界面

        scanf("%d",&flag3);//输入菜单选择
        switch (flag3)
        {
        case 2:
            chaxunhuobi();//查询存币
            break;
        case 1:
            genggaishangping();
            break;
        default:
            break;
        }//switch
    }//while
    system("color 07");
}//guanliyuanmoshi

void chaxunhuobi()
{
    int key;//操作键
    int money;//提取金额
    while(1)
    {
        system("cls");//更新显示提示
        printf("机内存币有:%d元\n",cunbi);
        printf("[1]提取存币\t[2]返回:");

        scanf("%d",&key);
        if(key == 1)//1为提取货币操作
        {
            printf("输入提取金额：");
            scanf("%d",&money);
            if(money <= cunbi)//当货币足够提取时
            {
                cunbi = cunbi - money;//取出货币
                system("cls");//动态显示
                printf("货币已提取出%d元,还存有%d元\n3",money,cunbi);
                Sleep(1000);//暂停显示
                system("cls");
                printf("货币已提取出%d元,还存有%d元\n2",money,cunbi);
                Sleep(1000);//暂停显示
                system("cls");
                printf("货币已提取出%d元,还存有%d元\n1",money,cunbi);
                Sleep(1000);
            }else{//当货币不足时
                printf("货币不足\n");
                system("pause>nul");//暂停提示信息
            }
        }else if(key == 2)
        {
            break;//跳出
        }//if
    }//while
}
//显示屏--------------------------------------------------------------------------------------
void genggaishangping()//管理员之更改商品信息--------------------------
{
    int num;//商品号
    int key = 2; //操作键
    char buf_name[20];
    int price;
    int i;
    //显示商品信息界面
    system("cls");
    xianshi_gengai();

    //选择对应商品进行更改
    scanf("%d",&num);
    if(num == -1)return;//取消更改
    //更改商品信息，商品名，价格
    printf("输入商品名：");
    getchar();//消除上一个的回车
    gets(buf_name);//输入商品名

    printf("输入商品价格：");
    scanf("%d",&price);//输入商品价格

    //确认更改
    while(key != 0 && key != 1)//只能输入1/0
    {
        printf("是否确认更改（1/0）：");
        scanf("%d",&key);
    }//while

    if(key == 1)//确认更改
    {
        for(i = 0; i < 20; i++)//更改名字
        {
            goods[num - 1].name[i] = buf_name[i];
        }//for
        goods[num - 1].price = price;//更改价格
        return;//退出
    }else if(key == 0){//取消更改
        return;//退出
    }
}

void guanliyuancaidan()//管理员菜单
{
    printf("|+++++++++++++++++++++++++++++++|\n");
    printf("|  [1]更改商品信息               |\n");
    printf("|  [2]查询机内货币               |\n");
    printf("|  [3]查询交易记录(lv.1暂时未实现)|\n");
    printf("|  [-1]退出                     |\n");
    printf("|+++++++++++++++++++++++++++++++|\n");
}

void xianshi_gengai()//商品信息----------------------------------------
{
    printf("|————————————————————————————————————————————————————|\n");
    printf("|  [ 1 ]     [ 2 ]     [ 3 ]    [ 4 ]     [ 5 ]      |\n");
    printf("|  %-10s%-10s%-10s%-10s%-10s|\n",goods[0].name,goods[1].name,goods[2].name,goods[3].name,goods[4].name);
    printf("|  %-3d元     %-3d元     %-3d元     %-3d元     %-3d元     |\n",goods[0].price,goods[1].price,goods[2].price,goods[3].price,goods[4].price);
    printf("|                                                    |\n");
    printf("|  [ 6 ]      [ 7 ]     [ 8 ]    [ 9 ]     [ 10 ]    |\n");
    printf("|  %-10s%-10s%-10s%-10s%-10s|\n",goods[5].name,goods[6].name,goods[7].name,goods[8].name,goods[9].name);
    printf("|  %-3d元      %-3d元     %-3d元     %-3d元     %-3d元    |\n",goods[5].price,goods[6].price,goods[7].price,goods[8].price,goods[9].price);
    printf("|————————————————————————————————————————————————————|\n");
    printf("                  输入更改编号(-1返回)：");
}
void xianshiping()//显示屏
{
    printf("|————————————————————————————————————————————————————|\n");
    printf("|  [ 1 ]     [ 2 ]     [ 3 ]    [ 4 ]     [ 5 ]      |\n");
    printf("|  %-10s%-10s%-10s%-10s%-10s|\n",goods[0].name,goods[1].name,goods[2].name,goods[3].name,goods[4].name);
    printf("|  %-3d元     %-3d元     %-3d元     %-3d元     %-3d元     |\n",goods[0].price,goods[1].price,goods[2].price,goods[3].price,goods[4].price);
    printf("|                                                    |\n");
    printf("|  [ 6 ]      [ 7 ]     [ 8 ]    [ 9 ]     [ 10 ]    |\n");
    printf("|  %-10s%-10s%-10s%-10s%-10s|\n",goods[5].name,goods[6].name,goods[7].name,goods[8].name,goods[9].name);
    printf("|  %-3d元      %-3d元     %-3d元     %-3d元     %-3d元    |\n",goods[5].price,goods[6].price,goods[7].price,goods[8].price,goods[9].price);
    printf("|                                                    |\n");
    printf("|  1:投币(-1结束投币)              余额[%04d]元      |\n",summoney);
    printf("|  2:购买商品                                        |\n");
    printf("|  3:管理员模式                                      |\n");
    printf("|  -1:取消交易                                       |\n");
    printf("|————————————————————————————————————————————————————|\n");
}

void xianshiping2()//显示屏2选择商品模式
{
    printf("|————————————————————————————————————————————————————|\n");
    printf("|  [ 1 ]     [ 2 ]     [ 3 ]    [ 4 ]     [ 5 ]      |\n");
    printf("|  %-10s%-10s%-10s%-10s%-10s|\n",goods[0].name,goods[1].name,goods[2].name,goods[3].name,goods[4].name);
    printf("|  %-3d元     %-3d元     %-3d元     %-3d元     %-3d元    |\n",goods[0].price,goods[1].price,goods[2].price,goods[3].price,goods[4].price);
    printf("|                                                    |\n");
    printf("|  [ 6 ]      [ 7 ]     [ 8 ]    [ 9 ]     [ 10 ]    |\n");
    printf("|  %-10s%-10s%-10s%-10s%-10s|\n",goods[5].name,goods[6].name,goods[7].name,goods[8].name,goods[9].name);
    printf("|  %-3d元      %-3d元     %-3d元     %-3d元     %-3d元    |\n",goods[5].price,goods[6].price,goods[7].price,goods[8].price,goods[9].price);
    printf("|                                                    |\n");
    printf("|  [1]:%-2d      [5]:%-2d      [9]:%-2d    余额[%04d]元    |\n",goods[0].tag,goods[4].tag,goods[8].tag,summoney);
    printf("|  [2]:%-2d      [6]:%-2d      [10]:%-2d                   |\n",goods[1].tag,goods[5].tag,goods[9].tag);
    printf("|  [3]:%-2d      [7]:%-2d      11:确认购买               |\n",goods[2].tag,goods[6].tag);
    printf("|  [4]:%-2d      [8]:%-2d      12:重新选择   -1:返回     |\n",goods[3].tag,goods[7].tag);
    printf("|————————————————————————————————————————————————————|\n");
}
void bianse()//随机变身色
{
    char color[] = "color  c";
    color[7] = '0' + rand() % 10;
    system(color);
}
int main()
{
    InitGoods();//初始化商品
    xianshiping();
    while( 1 )
    {
        caidan();//菜单选择
        system("cls");//重新显示
        xianshiping();
    }//while
}
