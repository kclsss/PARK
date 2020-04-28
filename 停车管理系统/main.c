
#include "project.h"

int main()
{
    // 初始化
    s.top   = -1;
    b.top   =  0;
    p.rear  =  0;
    p.count =  0;
    p.front =  0;
    while(1)
    {
        //system("clear");
        welcome();
        char che[1];
	char i[1];
        scanf ("%s", &i);

        if ('1' == i[0]) get_in();
        if ('2' == i[0]) get_out();
        if ('3' == i[0]) information();
        if ('4' == i[0]) break;
        if (i[0]!='1'&&i[0]!='2'&&i[0]!='3'&&i[0]!='4')
	{
	    printf("您的输入有误，请重新输入\n");
	}
        printf("返回菜单,请输入1\n");

        while(1)
        {
            scanf("%s",&che);
            if('1' == che[0])
            {
                break;
            }
            else
            {
                printf("您的输入有误，请重新输入\n");
            }
        }
    }
    return 0;
}

