#include "background.h"
#include "JumpChoice.h"
char name[20];
int score = 0;
int i;

void Welcome()  //开始背景
{


//打出一个框框
   gotoXY(10,2);
   printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■");//28个■ 56个字符
   for(i=3; i<18; i++)
   {
     gotoXY(10,i);  //到windows操作框的坐标位置处
     printf("■");   //x坐标是10
   }
   for(i=3; i<18; i++)
   {
     gotoXY(64,i); //竖的第二个框要在横着最后一个下面 所以10+(27*2)=64
     printf("■");
   }
   gotoXY(10,18);
   printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

//框框里输入字
   gotoXY(22,5);  //到某个位置 开始打印
   printf("欢迎来到Delires创作的贪吃蛇");
   gotoXY(22,6);
   printf("您可以随意复制这个程序,祝你技术进步");
   gotoXY(22,7);
   printf("QQ:985550861");
   gotoXY(22,9);
   printf("w上s下a左d右");
   gotoXY(22,11);
   printf("请输入你的名字:");
   scanf("%s", &name, 15);
   system("cls");//清屏
}



//注意score值要从别的函数得来
void Finish()  //结束函数
{
   system("cls");//清屏
//打出一个框框
   gotoXY(10,2);
   printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

   //框框里输入字
   gotoXY(22,5);
   printf("本程序由Delires创作");
   gotoXY(22,6);
   printf("QQ:985550861");
   gotoXY(22,8);
   printf("游戏结束，再接再厉");
   gotoXY(22,9);
   printf("您的分数为%d", score);
   for(i=3; i<18; i++)
   {
     gotoXY(10,i);
     printf("■");
   }

   for(i=3; i<18; i++)
   {
     gotoXY(64,i);
     printf("■");
   }
   gotoXY(10,18);
   printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

   gotoXY(10,20);
   //system("pause");//控制台暂停程序
}


