#include "justicAcoordinate.h"

//返回0 游戏结束   1游戏继续
int Judge()
{//碰到墙
    if (head->x==0||head->x==56||head->y==0||head->y==20)
    {
        Finish();  //为啥注释了这句为啥蛇能随便吃？？问题
        return 0;
    }
    snake *p = head->next;
    while(1)
    {
        if(p->next == NULL) break; //一直到蛇尾都没碰到，跳出while 返回1
        if(head->x == p->x && head->y == p->y)//蛇碰到自己
        {
            Finish();
            return 0;
        }
        p = p->next; //连接到身子下一截
    }
    return 1;
}
