#include "JumpChoice.h"

void gotoXY(int x, int y) //��굽һ����
{
   COORD place; //COORD windows��ɵ�һ���ṹ�� ��ֵ��xy����
   HANDLE inDex; //����һ��������������һ������(��������Ļ�����)
                //ʵ����ָ��ָ���ָ�룬�������ַ
                //�������ͨ����hOut
   place.X = x;
   place.Y = y;  //��������Ĺ��λ�ø���windows
   inDex = GetStdHandle(STD_OUTPUT_HANDLE); //�ú����õ�һ�����
              //STD_INPUT_HANDLE----��׼������   ���̵�����
              //STD_OUTPUT_HANDLE----��׼������  ��Ļ������
              //STD_ERROR_HANDLE----��׼������   ��Ļ������
   SetConsoleCursorPosition(inDex,place); //���ù��λ��
   SetConsoleTextAttribute(inDex,FOREGROUND_GREEN);//���øþ��������ɫ
                 //�ú���������������������Ļ��  Ȼ�������ù��
}


void gotoPrint(int x, int y) //��һ���㿪ʼ��ӡ��
{
    gotoXY(x, y);
    printf("��");
}


void gotoDelete(int x, int y)//��һ���㿪ʼ��ӡ�հ� �൱��ɾ��
{
    gotoXY(x, y);
    printf("  ");
}
