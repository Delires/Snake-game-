#ifndef JIANPAN_H_INCLUDED
#define JIANPAN_H_INCLUDED
//�����������˻�����������ûŪ��
//�������� �������� �ƶ����� ��ʳ�ﺯ��
#include "JumpChoice.h"
#include "justicAcoordinate.h"
#include "conio.h"    //_getch()��������
#include "WallFood.h" //_kbhit()�жϼ������뺯����ͷ�ļ�
//���ü���
#define up    'w'
#define down  's'
#define left  'a'
#define right 'd'
#define stop  'p'


extern char click; //.h�ļ�extern�ⲿ���� .c���嶨��
extern int speed;

int ClickControl();     //����(����)����
void MovingBody();      //�������ߵ��ƶ�
void Eating();    //��ʳ����
void ChangeBody(int a, int b); //�ı��ߵ�����

#endif // JIANPAN_H_INCLUDED
