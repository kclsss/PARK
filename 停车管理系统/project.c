//
//Copyright:李文锐
//Author:李文锐
//Data:2019-01-08
//Description:停车管理系统
//Emile:1075800094@qq.com
//

#include "project.h"

void enter_to_lane()                        // 汽车进入车道
{
    // 判断队满
    if (p.count > 0 && (p.front == (p.rear + 1) % MAX_PAVE))
    {
        printf ("车道已满，稍等片刻\n");
    }
    else
    {
        strcpy(p.Pave[p.rear].plate, C);    // 汽车进入车道
        p.rear = (p.rear + 1) % MAX_PAVE;   // 队尾指示器加1
        p.count++;                          // 计数器加1
        printf ("车牌为%s的汽车进入车道上的%d的位置\n", C, p.rear);
    }
}

void get_in()                               // 汽车进入停车位
{
    printf ("请输入停车的车牌号:");            // 输入车牌号
    scanf ("%s", &C);
    if (s.top >= MAX_STOP - 1)              // 如果停车位已满，进入车道
    {
        enter_to_lane();                    // 汽车进入车道
    }
    else
    {
        s.top++;                            // 停车位栈顶指针加1
        time_t t1;
        long int t = time(&t1);             // 记录进入停车场的时间
        char* t2;
        t2 = ctime (&t1);                   // 将当前时间转换为字符串
        s.Stop[s.top].timeIn = t;
        strcpy(s.Stop[s.top].plate, C);     // 将车牌号登记
        printf ("车牌为%s的汽车进入停车位的%d车位\n当前时间:%s\n", C, s.top + 1, t2);
    }
    return ;
}

void enter_to_buff()                        // 汽车进入让路栈
{
    // 停车位栈压入临时栈，为需要出栈的车辆让出道
    while (s.top >= 0)
    {
        if (0 == strcmp(s.Stop[s.top].plate, C))
        {
            break;
        }
        // 让离开的车进入让路栈
        strcpy(b.Help[b.top++].plate, s.Stop[s.top].plate);
        printf ("车牌为%s的汽车暂时离开停车场\n", s.Stop[s.top--].plate);
    }

    // 如果停车位中的车都让了道，说明停车位中无车辆需要出行
    if (s.top < 0)
    {
        printf ("停车位上无车辆出行消息\n");
    }
    else
    {
        printf ("车牌为%s的汽车从停车场离开\n", s.Stop[s.top].plate);
        time_t t1;
        long int t = time (&t1);
        c.timeOut = t;                      // 标记离开停车场的时间
        char* t2;
        t2 = ctime (&t1);                   // 获取当前时间
        printf ("离开时间:%s\n停车费:%ld元\n", t2, (c.timeOut - s.Stop[s.top].timeIn)/10);
        printf("欢迎下次再来\n");
        s.top--;
    }

    // 将让路栈中的车辆信息压入停车位栈
    while (b.top > 0)
    {
        strcpy(s.Stop[++s.top].plate, b.Help[--b.top].plate);
        printf ("车牌为%s的汽车停回停车位%d车位\n", b.Help[b.top].plate, s.top);
    }

    // 从便道中 -> 停车位
    while (s.top < MAX_STOP-1)
    {
        if (0 == p.count)                   // 判断队列是否为空
        {
            break;
        }   
        // 不为空，将便道中优先级高的车停入停车位
        else
        {
            strcpy(s.Stop[++s.top].plate, p.Pave[p.front].plate);
            printf ("车牌为%s的汽车从车道中进入停车位的%d车位\n", p.Pave[p.front].plate, s.top);
            p.front = (p.front + 1) % MAX_PAVE;
            p.count--;
        }
    }
}

void get_out()                              // 汽车离开
{
    printf ("请输入即将离开的车牌号:\n");
    scanf ("%s", &C);
    if (s.top < 0)                          // 判断停车位是否有车辆信息
    {
        printf ("车位已空，无车辆信息\n");
    }
    else
    {
        enter_to_buff();
    }
}

void information()
{
    int i = s.top;
    if (-1 == i)
    {
        printf ("停车场为空\n");
    }
    time_t t1;
    long int t = time(&t1);                 // 标记显示时的时间
    printf ("\t车牌号\t\t停放时间\t\t当前所需支付金额\n");
    while (i != -1)
    {
        printf ("\t%s\t\t%d秒\t\t%d元\n", s.Stop[i].plate, t - s.Stop[i].timeIn, (t - s.Stop[i].timeIn)/10);
        i--;
    }
}

void welcome()
{
    printf ("\t*****************************************************\n");
    printf ("\t----------<<<<<Welcome to the Parking>>>>>-----------\n");
    printf ("\t*                     1.Park                        *\n");
    printf ("\t*                     2.Leave                       *\n");
    printf ("\t*                     3.Information                 *\n");
    printf ("\t*                     4.Exit                        *\n");
    printf ("\t* 停车场共有%d个车位-停车场现有%d辆车-等候区共有%d辆车*\n", MAX_STOP, s.top+1,        (p.rear + MAX_PAVE - p.front)% MAX_PAVE);
    printf ("\t*****************************************************\n");
}

