#include "jianpan.h"

char click=1;  //���ڴ�Ŷ�ȡ�ļ�ֵ���ȸ�1�»���
int speed;  //�����ߵ��ٶ�

//����(����)����
int ClickControl()
{
 while(1)
 {
   if(Judge()==0) return 0; //�ж���Ϸʧ�ܷ���0,����ʧ��
   if(kbhit()) //kbhit()�ж����޼��̰��� �з��ط���
   {
      click = getch(); //�������̲���ʾ���ظ�click
   }
   MovingBody(); //���ݶ����ƶ�����
   Eating();     //�ж��Ƿ�Ե�ʳ��  ����ɹ������ڵ����ڶ����һλ
 }
  return 1; //�����ɹ�����1
}


void MovingBody()       //�������ߵ��ƶ�
{
    int count = 0; //count��¼�ߵĳ���
    int a=head->x, b=head->y;//��ͷ�����ab ab������ͷhead������
    snake *p = head; //head�Ľṹ��ָ��p ����p���ǲ���head ��������ȥ���ƺ�211ɱ�� ���ܰ����ƺŸ�˭����ɱ221����
                //�ṹ��head�����ڲ�������������
                //�ṹ��p �����ڴ�ӡ�ߵĹ켣

//����while()�����ڵ�ɾ�� ��ĩβ���� �ٰ����ڵ��ӡ Ӫ��������ƶ���
    while(1)
    {
        if(p->next == NULL) break; //��βָ�������
        gotoDelete(p->x, p->y);
        count++; //��¼�߳������Ѷ�
        p = p->next; //��������
    }

    switch(click)//���ݶ����ı��߷���
    {
      case up:
          head->y -=1; //�ٴδ�ӡʱy�����1  Ӫ������
                       //ֻ��ͷ�������1�б仯��������أ� ��ʱ��Ҫchangbody���������ð�����һ����������
          ChangeBody(a, b);
                  //ab������ͷhead�����꣬�ı���ͷ��xy���Ǹı�ab
          break;
      case down:
          head->y +=1;  //�ٴδ�ӡʱy�����1Ӫ������
          ChangeBody(a, b);
           break;
      case left:
          head->x -=2; //�ٴδ�ӡʱx�������2 Ӫ������
          ChangeBody(a, b);
           break;
      case right:
          head->x +=2; //�ٴδ�ӡʱx�����2  Ӫ��������
          ChangeBody(a, b);
           break;
      case stop:
          break;
    }
//�߾����ƶ� �����°�head����p ��ӡ������ɶ���Ч��
    p = head;
    while(1)
    {
        if(p->next == NULL) break;
        gotoPrint(p->x, p->y);
        p=p->next; //��������
    }

    p=head;
   //gotoXY(0,50); //���ÿ�ζ����м�һ��λ�ã������á�
//���������ӳ������ٶ�,Խ���ٶ�Խ��
    if(count<=10) speed=150;
    else if (count>10 && count<=20) speed=100;
    else if (count>20 && count<=40) speed=50;
    else speed = 10;
    Sleep(speed); //Sleep()�������ߺ��� ͨ���ó������е�����ʱ��ı��ٶ�

}


//�Ե��˾��ڵ����ڶ����͵�����һ����һ��
//û�Ե�������
void Eating()   //��ʳ����
{
    if(head->x == food.x && head->y == food.y)
    {//�Ե�ʳ��
        CreatFood(); //������ʳ��
      //����һ��������  *_new ���ڼӵ���������ȥ
        snake *_new = (snake*)malloc(sizeof(snake)); //��ʳ������ָ������ڴ�
        snake *p;
        p =head; //ͷ��ֵ��p
        while(1)
        {//�����������ڶ��� ��ΪҪ�ڵ����ڶ����͵�����һ����һ��
         //����������������ڶ��� ��һֱ��while()ѭ����
            if(p->next->next == NULL) break; //�����ڶ�������
            p= p->next;
        }
//��һ�������ȥ (MoveBoday���ӡ��һ�� �����߱䳤)
        p->next = _new; //_new�ӵ������ڶ�����β��֮��
        _new->next = tail;

        score+=10;
        gotoXY(73,4); //������ӡ������ ˢ�·���
        printf("%d", score);
    }
}


//ÿ�ζ�����ͷ����仯 ��ֻ����ͷλ�ñ仯 ChangeBody()�������ǰѺ���������һ��仯
void ChangeBody(int a, int b) //�ı��ߵ����� a,bΪ��ͷ�Ѿ��ı�������
{
    snake *p = head->next; //���ߵĵ�2�ظ�p
    int mid1, mid2, _mid1, _mid2;//�����ĸ�����
    mid1 = p->x;
    mid2 = p->y; //2��mid1 mid2
    while(1)
    {
       if(p->next == NULL) break; //�ж��ǲ������һ�� ���һ��ָ��NULL ����
           //if(p->next->next == NULL) break;  //Ҳ�� ��Ϊ1�ڴ�һ��ʼMove��������ǰ�� �����պ�������
       _mid1 = p->next->x;  //3�ص�ֵ��_mid1        4�ص�ֵ�� _mid1
       _mid2 = p->next->y;

//p->next->y�����м���� �ֳе�������������������
       p->next->x = mid1;
       p->next->y = mid2;   //2�ص�ֵ��p->next->x(���ڶ��ڵ�ֵ���˵�����)   3�ص�ֵ��p->next->x

       mid1 = _mid1;        //3�ص�ֵ��2�ص�ֵ      4�ص�ֵ��3�ص�ֵ        ����������������
       mid2 = _mid2;

       p = p->next;         //����һ��      ����һ��  p->next->x�ǵڶ��ڵ�ֵ  ����p->next->x��ɵ�����ֵ
       //�ѵ�2�ص�ֵ����3�ص�ֵ �ѵ�3�ص�ֵ����4�ص�ֵ(����һ�ص�ֵ�¸�һ�أ�������һ�ؾ���ǰ��һ��)
                                               //��������һ����ǰ�ܵĸо�
    }

//ΪʲôҪ�ѵڶ��ص�ֵ�������ص���������أ�
//���������while(1)�� ֱ�Ӱѵڶ������� ��ֱ������һ�� ֱ�Ӿ���Ϸ������
    p = head->next;
	//if (p->next!= NULL)
	{
		p->x = a;    //�ѵ�1�ص�ֵ ����2��(��2�ر�1����ǰ��)
		p->y = b;
	}
	  //1�ڴ�һ��ʼMove�����ͱ���

}
