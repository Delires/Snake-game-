#include "WallFood.h"
#include "JumpChoice.h"
#include "background.h"

snake *head, *tail;


void CreatWall()//������Ϸ����
{
//������Ϸ�� ������x����ռ2�ַ� y����ռ1�ַ�
    int i;
	for (i = 0; i<58; i+= 2)//��ӡ���±߿� x����ռ2�ַ�
	{                  //����ռ�����ַ�
		gotoPrint(i, 0); //ֱ�Ӵ�ӡ������
		gotoPrint(i, 20);
	}
    for (i = 1; i < 20; i++) //��ӡ�������߿�
	{
		gotoPrint(0, i); //����ռһ���ַ�
		gotoPrint(56, i);
	}
//��Ϸ���Ҳ���ʾ ��ӭ ���� ����
	gotoXY(60,2);
	printf("Welcome to Game");
	gotoXY(60,3);
	printf("Hello,%s!",name);
	gotoXY(60,4);
	printf("You Score:  %d",score);
	gotoXY(60,20);
	printf("Delires����\n");


//����һ��������Ϊ�����ӣ�head��ͷ
//�˴�ֻ�����ڴ��и������һ�������� ��δ��ӡ����
//                       ��MoveBoday()������ ��ӡ�����������������ʾ����
	head = (snake*)malloc(sizeof(snake));
	snake *p = (snake*)malloc(sizeof(snake));
	snake *q = (snake*)malloc(sizeof(snake));
	tail = (snake*)malloc(sizeof(snake));//�ղ���ֵ
//��head p q tailָ�����snakeָ���͵�snake�ĳ���  ��ָ����䳤�Ȳ��ܸ�ֵ
//���������ӣ�����������������
    head->x=16;  //ָ�븳ֵ��->  ���������ֵ��.
    head->y=15;
    head->next = p;
    p->x = 16;
    p->y = 16;
    p->next = q;
    q->x = 16;
    q->y = 17;
    q->next = tail;
    tail->next = NULL; //tail���������ӳ��ȵ�

}




void CreatFood()//����ʳ��
{
    srand((int)time(NULL));//srand()������rand()����ʹ��ǰ������������
            //time()����������ֵ(��1970�����ڵ�����)��time(null)��ʱ����0 Ȼ��õ���ǰʱ��  ��֮���ǲ����������
    lable: //����goto�����ת
    food.x = rand()%(54-2+1)+2;//���[2,56]
    food.y = rand()%19+1;      //����[1,19]
            //rand()��������� 2~54 1~19֮��
//rane%(54-2+1)+2 ���Ǳ��緶Χ�� [x,y]��ô�����ڴ˷�Χ�������� rand()%(y-x+1) + x
    if(food.x % 2 !=0)//��ֹ���ɵ�2�ı������Բ���
    {                 //
        food.x+=1;
    }

    //����������ĵط���ʳ��
	gotoXY(food.x, food.y);
	printf("��");

    snake *judge = head;//����ͷ���µ�ָ��

    while(1)//�߳Ե�ʳ�����������������ӡʵ�� û�Ե�������while()��������
    {      //judge��ͷָ������->
        if(judge->next ==NULL) break;//���������û�Ե� �������� ��������߼�����
        if(judge->x==food.x && judge->y==food.y)//�Ե�ʳ��
        {
            goto lable; //���������������ת        }
        }
        judge  = judge->next; //���������������ȥ
    }

}
