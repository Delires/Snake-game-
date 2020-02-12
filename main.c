#include "stdio.h"
#include "delay.h"
#include "background.h"
#include "JumpChoice.h"
#include "justicAcoordinate.h"
#include "jianpan.h"

int main()
{
    while(1)
    {
        system("color 0B"); //…Ë÷√—’…´

        Welcome();
        CreatWall();
        CreatFood();

        if( ClickControl() == 0) return 0;
        return 0;
    }
}


