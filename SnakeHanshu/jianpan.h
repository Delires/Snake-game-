#ifndef JIANPAN_H_INCLUDED
#define JIANPAN_H_INCLUDED
//读键函数，人机交互。从来没弄过
//三个函数 读键函数 移动函数 吃食物函数
#include "JumpChoice.h"
#include "justicAcoordinate.h"
#include "conio.h"    //_getch()读键函数
#include "WallFood.h" //_kbhit()判断键盘输入函数的头文件
//设置键盘
#define up    'w'
#define down  's'
#define left  'a'
#define right 'd'
#define stop  'p'


extern char click; //.h文件extern外部声明 .c具体定义
extern int speed;

int ClickControl();     //操作(读键)函数
void MovingBody();      //读键后蛇的移动
void Eating();    //吃食函数
void ChangeBody(int a, int b); //改变蛇的坐标

#endif // JIANPAN_H_INCLUDED
