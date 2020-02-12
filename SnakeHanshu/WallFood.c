#include "WallFood.h"
#include "JumpChoice.h"
#include "background.h"

snake *head, *tail;


void CreatWall()//生成游戏界面
{
//生成游戏框 ■左右x方向占2字符 y方向占1字符
    int i;
	for (i = 0; i<58; i+= 2)//打印上下边框 x方向占2字符
	{                  //横着占两个字符
		gotoPrint(i, 0); //直接打印■函数
		gotoPrint(i, 20);
	}
    for (i = 1; i < 20; i++) //打印左右两边框
	{
		gotoPrint(0, i); //竖着占一个字符
		gotoPrint(56, i);
	}
//游戏框右侧显示 欢迎 姓名 分数
	gotoXY(60,2);
	printf("Welcome to Game");
	gotoXY(60,3);
	printf("Hello,%s!",name);
	gotoXY(60,4);
	printf("You Score:  %d",score);
	gotoXY(60,20);
	printf("Delires制作\n");


//构造一个链表作为蛇身子，head是头
//此处只是在内存中搞出来了一个数据链 并未打印出来
//                       在MoveBoday()函数中 打印出来这个数据链即显示蛇身
	head = (snake*)malloc(sizeof(snake));
	snake *p = (snake*)malloc(sizeof(snake));
	snake *q = (snake*)malloc(sizeof(snake));
	tail = (snake*)malloc(sizeof(snake));//空不赋值
//给head p q tail指针分配snake指针型的snake的长度  给指针分配长度才能赋值
//做出蛇身子，并且用链表连起来
    head->x=16;  //指针赋值用->  定义变量赋值用.
    head->y=15;
    head->next = p;
    p->x = 16;
    p->y = 16;
    p->next = q;
    q->x = 16;
    q->y = 17;
    q->next = tail;
    tail->next = NULL; //tail是用来增加长度的

}




void CreatFood()//生成食物
{
    srand((int)time(NULL));//srand()函数给rand()函数使用前产生个种子数
            //time()函数是尼林值(从1970到现在的秒数)，time(null)把时间清0 然后得到当前时间  总之就是产生个随机数
    lable: //用于goto语句跳转
    food.x = rand()%(54-2+1)+2;//宽度[2,56]
    food.y = rand()%19+1;      //长度[1,19]
            //rand()产生随机数 2~54 1~19之间
//rane%(54-2+1)+2 就是比如范围是 [x,y]那么产生在此范围的数就是 rand()%(y-x+1) + x
    if(food.x % 2 !=0)//防止生成到2的倍数处吃不到
    {                 //
        food.x+=1;
    }

    //随机生成数的地方打食物
	gotoXY(food.x, food.y);
	printf("⊙");

    snake *judge = head;//把蛇头给新的指针

    while(1)//蛇吃到食物重新生成随机数打印实物 没吃到就跳出while()函数结束
    {      //judge是头指针所以->
        if(judge->next ==NULL) break;//遍历到最后没吃到 跳出函数 程序结束蛇继续走
        if(judge->x==food.x && judge->y==food.y)//吃到食物
        {
            goto lable; //重新生成随机数跳转        }
        }
        judge  = judge->next; //蛇身继续遍历连下去
    }

}
