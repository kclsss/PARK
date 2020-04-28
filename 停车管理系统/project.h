//
//Copyright:李文锐
//Author:李文锐
//Data:2019-01-08
//Description:停车管理系统
//Emile:1075800094@qq.com
//

#ifndef __PROJECT_H__
#define __PROJECT_H__

#define Price    1           // 定义价格n
#define MAX_STOP 10
#define MAX_PAVE 10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>            // 包含时间函数的头文件

// 汽车信息
typedef struct
{
    int timeIn;              // 进入停车场时间 
    int timeOut;             // 离开停车场时间
    char plate[10];          // 车牌号码，定义一个字符指针类型
}Car;

// 停放栈
typedef struct
{
    Car Stop[MAX_STOP];      // 停放车辆的栈
    int top;                 // 标记栈顶位置
}Stopping;

// 等候队列
typedef struct
{
    int count;               // 用来指示队列的数据个数
    Car Pave[MAX_PAVE];      // 等候停车的队列
    int front,rear;          // 标记队头和队尾的位置
}Pavement;

// 让路栈
typedef struct
{
    Car Help[MAX_STOP];      // 用于让路的队列
    int top;                 // 标记定位
}Buffer;

Stopping s;
Pavement p;
Buffer   b;
Car      c;
char     C[10];

void enter_to_lane();        // 汽车进入车道
void get_in       ();        // 汽车进入停车位
void enter_to_buff();        // 汽车进入让路栈
void get_out      ();        // 汽车离开
void welcome      ();        // 主界面函数
void information  ();        // 显示车辆信息

#endif //__PROJECT_H__

