#include "justicAcoordinate.h"

//����0 ��Ϸ����   1��Ϸ����
int Judge()
{//����ǽ
    if (head->x==0||head->x==56||head->y==0||head->y==20)
    {
        Finish();  //Ϊɶע�������Ϊɶ�������ԣ�������
        return 0;
    }
    snake *p = head->next;
    while(1)
    {
        if(p->next == NULL) break; //һֱ����β��û����������while ����1
        if(head->x == p->x && head->y == p->y)//�������Լ�
        {
            Finish();
            return 0;
        }
        p = p->next; //���ӵ�������һ��
    }
    return 1;
}
