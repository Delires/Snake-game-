#ifndef WALLFOOD_H_INCLUDED
#define WALLFOOD_H_INCLUDED

#include "stdio.h"

typedef struct Snakes //�ߵĽṹ��
{
    int x;
    int y;
    struct Snakes *next;  //�ṹ��Ƕ�� ��������ƶ�
}snake;    //��typedef��������ֱ����snakeȥ����ṹ��


struct Food  //ʳ��Ľṹ��
{
    int x;
    int y;
}food; //δ��typedef �Ͳ�����food����

extern snake *head, *tail;

void CreatWall();//����Χǽ
void CreatFood();//����ʳ��

#endif // WALLFOOD_H_INCLUDED
