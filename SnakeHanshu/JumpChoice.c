#include "JumpChoice.h"

void gotoXY(int x, int y) //光标到一个点
{
   COORD place; //COORD windows变成的一个结构体 赋值是xy变量
   HANDLE inDex; //设置一个句柄，句柄类似一个索引(索引到屏幕或键盘)
                //实质是指向指针的指针，即虚拟地址
                //句柄设置通常是hOut
   place.X = x;
   place.Y = y;  //函数输入的光标位置赋给windows
   inDex = GetStdHandle(STD_OUTPUT_HANDLE); //用函数得到一个句柄
              //STD_INPUT_HANDLE----标准输入句柄   键盘的索引
              //STD_OUTPUT_HANDLE----标准输出句柄  屏幕的索引
              //STD_ERROR_HANDLE----标准错误句柄   屏幕的索引
   SetConsoleCursorPosition(inDex,place); //设置光标位置
   SetConsoleTextAttribute(inDex,FOREGROUND_GREEN);//设置该句柄光标的颜色
                 //该函数先输入句柄即索引到屏幕处  然后再设置光标
}


void gotoPrint(int x, int y) //从一个点开始打印■
{
    gotoXY(x, y);
    printf("■");
}


void gotoDelete(int x, int y)//从一个点开始打印空白 相当于删除
{
    gotoXY(x, y);
    printf("  ");
}
