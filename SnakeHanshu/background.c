#include "background.h"
#include "JumpChoice.h"
char name[20];
int score = 0;
int i;

void Welcome()  //��ʼ����
{


//���һ�����
   gotoXY(10,2);
   printf("��������������������������������������������������������");//28���� 56���ַ�
   for(i=3; i<18; i++)
   {
     gotoXY(10,i);  //��windows�����������λ�ô�
     printf("��");   //x������10
   }
   for(i=3; i<18; i++)
   {
     gotoXY(64,i); //���ĵڶ�����Ҫ�ں������һ������ ����10+(27*2)=64
     printf("��");
   }
   gotoXY(10,18);
   printf("��������������������������������������������������������");

//�����������
   gotoXY(22,5);  //��ĳ��λ�� ��ʼ��ӡ
   printf("��ӭ����Delires������̰����");
   gotoXY(22,6);
   printf("���������⸴���������,ף�㼼������");
   gotoXY(22,7);
   printf("QQ:985550861");
   gotoXY(22,9);
   printf("w��s��a��d��");
   gotoXY(22,11);
   printf("�������������:");
   scanf("%s", &name, 15);
   system("cls");//����
}



//ע��scoreֵҪ�ӱ�ĺ�������
void Finish()  //��������
{
   system("cls");//����
//���һ�����
   gotoXY(10,2);
   printf("��������������������������������������������������������");

   //�����������
   gotoXY(22,5);
   printf("��������Delires����");
   gotoXY(22,6);
   printf("QQ:985550861");
   gotoXY(22,8);
   printf("��Ϸ�������ٽ�����");
   gotoXY(22,9);
   printf("���ķ���Ϊ%d", score);
   for(i=3; i<18; i++)
   {
     gotoXY(10,i);
     printf("��");
   }

   for(i=3; i<18; i++)
   {
     gotoXY(64,i);
     printf("��");
   }
   gotoXY(10,18);
   printf("��������������������������������������������������������");

   gotoXY(10,20);
   //system("pause");//����̨��ͣ����
}


