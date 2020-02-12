#include "jianpan.h"

char click=1;  //用于存放读取的键值，先给1怕混乱
int speed;  //设置蛇的速度

//操作(读键)函数
int ClickControl()
{
 while(1)
 {
   if(Judge()==0) return 0; //判定游戏失败返回0,读键失败
   if(kbhit()) //kbhit()判断有无键盘按下 有返回非零
   {
      click = getch(); //读到键盘不显示返回给click
   }
   MovingBody(); //根据读键移动蛇身
   Eating();     //判断是否吃到食物  如果成功链表在倒数第二格加一位
 }
  return 1; //读键成功返回1
}


void MovingBody()       //读键后蛇的移动
{
    int count = 0; //count记录蛇的长度
    int a=head->x, b=head->y;//蛇头坐标给ab ab就是蛇头head的坐标
    snake *p = head; //head的结构体指向p 操作p就是操作head 比如让你去门牌号211杀人 不管把门牌号给谁都是杀221的人
                //结构体head是用于操作读键后的情况
                //结构体p 是用于打印蛇的轨迹

//两个while()挨个节点删除 到末尾跳出 再挨个节点打印 营造出动画移动感
    while(1)
    {
        if(p->next == NULL) break; //到尾指向空跳出
        gotoDelete(p->x, p->y);
        count++; //记录蛇长增加难度
        p = p->next; //蛇往下连
    }

    switch(click)//根据读键改变蛇方向
    {
      case up:
          head->y -=1; //再次打印时y坐标减1  营造向上
                       //只是头的坐标减1有变化，后面的呢？ 这时就要changbody函数起作用把他们一次链接起来
          ChangeBody(a, b);
                  //ab就是蛇头head的坐标，改变蛇头的xy就是改变ab
          break;
      case down:
          head->y +=1;  //再次打印时y坐标加1营造向下
          ChangeBody(a, b);
           break;
      case left:
          head->x -=2; //再次打印时x坐标向减2 营造左移
          ChangeBody(a, b);
           break;
      case right:
          head->x +=2; //再次打印时x坐标加2  营造往右走
          ChangeBody(a, b);
           break;
      case stop:
          break;
    }
//蛇经过移动 再重新把head付给p 打印出来搞成动画效果
    p = head;
    while(1)
    {
        if(p->next == NULL) break;
        gotoPrint(p->x, p->y);
        p=p->next; //蛇往下连
    }

    p=head;
   //gotoXY(0,50); //光标每次都到中间一个位置，拉屏用。
//根据蛇身子长设置速度,越长速度越快
    if(count<=10) speed=150;
    else if (count>10 && count<=20) speed=100;
    else if (count>20 && count<=40) speed=50;
    else speed = 10;
    Sleep(speed); //Sleep()程序休眠函数 通过让程序运行的滞留时间改变速度

}


//吃到了就在倒数第二个和倒数第一个加一截
//没吃到继续走
void Eating()   //吃食函数
{
    if(head->x == food.x && head->y == food.y)
    {//吃到食物
        CreatFood(); //产生新食物
      //设置一个新数组  *_new 用于加到蛇身子里去
        snake *_new = (snake*)malloc(sizeof(snake)); //给食物的这个指针分配内存
        snake *p;
        p =head; //头赋值给p
        while(1)
        {//遍历到倒数第二个 因为要在倒数第二个和倒数第一个加一截
         //如果遍历不到倒数第二个 就一直在while()循环里
            if(p->next->next == NULL) break; //倒数第二个跳出
            p= p->next;
        }
//加一个链表进去 (MoveBoday多打印出一个 表明蛇变长)
        p->next = _new; //_new加到倒数第二个和尾巴之间
        _new->next = tail;

        score+=10;
        gotoXY(73,4); //跳到打印分数处 刷新分数
        printf("%d", score);
    }
}


//每次读键后头坐标变化 可只是蛇头位置变化 ChangeBody()函数就是把后面连起来一起变化
void ChangeBody(int a, int b) //改变蛇的坐标 a,b为蛇头已经改变后的坐标
{
    snake *p = head->next; //将蛇的第2截给p
    int mid1, mid2, _mid1, _mid2;//定义四个变量
    mid1 = p->x;
    mid2 = p->y; //2截mid1 mid2
    while(1)
    {
       if(p->next == NULL) break; //判断是不是最后一个 最后一节指向NULL 跳出
           //if(p->next->next == NULL) break;  //也对 因为1节从一开始Move函数就往前了 这样刚好数量够
       _mid1 = p->next->x;  //3截的值给_mid1        4截的值给 _mid1
       _mid2 = p->next->y;

//p->next->y即做中间变量 又承担把他们连起来的责任
       p->next->x = mid1;
       p->next->y = mid2;   //2截的值给p->next->x(即第二节的值给了第三节)   3截的值给p->next->x

       mid1 = _mid1;        //3截的值给2截的值      4截的值给3截的值        依次类推往下连接
       mid2 = _mid2;

       p = p->next;         //往下一个      往下一个  p->next->x是第二节的值  现在p->next->x变成第三节值
       //把第2截的值给第3截的值 把第3截的值给第4截的值(把上一截的值下给一截，这样下一截就往前了一节)
                                               //这样就有一种向前跑的感觉
    }

//为什么要把第二截的值给第三截单独领出来呢？
//如果都放在while(1)里 直接把第二给第三 就直接碰到一起 直接就游戏结束了
    p = head->next;
	//if (p->next!= NULL)
	{
		p->x = a;    //把第1截的值 给第2截(即2截变1节向前进)
		p->y = b;
	}
	  //1节从一开始Move函数就变了

}
