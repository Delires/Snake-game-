#ifndef WALLFOOD_H_INCLUDED
#define WALLFOOD_H_INCLUDED

#include "stdio.h"

typedef struct Snakes //蛇的结构体
{
    int x;
    int y;
    struct Snakes *next;  //结构体嵌套 用于射的移动
}snake;    //加typedef这样可以直接用snake去定义结构体


struct Food  //食物的结构体
{
    int x;
    int y;
}food; //未加typedef 就不能用food定义

extern snake *head, *tail;

void CreatWall();//生成围墙
void CreatFood();//生成食物

#endif // WALLFOOD_H_INCLUDED
