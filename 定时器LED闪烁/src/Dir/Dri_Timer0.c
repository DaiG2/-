#include "Dri_Timer0.h"
#define T1MS (65536 - FOSC / NT / 1000)
void Timer0_Init()
{
    // 中断总开关
    EA = 1;

    // 定时器0开关
    ET0 = 1;

    // 定时器工作方式
    TMOD &= 0xF0;
    TMOD |= 0x09;

    // 设置计数器脉冲初始值
    TL0 = T1MS;
    TH0 = T1MS >> 8;

    // 启动定时器
    TR0 = 1;
    P32 = 0;

}