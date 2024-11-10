/*
 * @Author: MinG
 * @Date: 2024-11-08 21:20:07
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-10 21:55:27
 * @Description: 
 * @FilePath: \定时器LED闪烁\src\main.c
 */
#include <STC89C5xRC.H>
#include "Com_Util.h"
#include "Dri_Timer0.h"
#define T1MS (65536 - FOSC / NT / 1000) // 1MS倒计时（12T模式）
#define SW3  P43
#define LED1 P00

/**
 * @description: 通过按键SW3来启动定时器
 * @return {*}
 * @author: MinG
 */
void main()
{
    Timer0_Init();
    while (1) {
        if (SW3 == 0) // 先检测按键是否被按下
        {
            Delay1ms(10); // 按下按键后延迟10ms，避免前沿抖动，
            if (SW3 == 0) // 再次判断按键是否抬起，如果抬起则会因为时间太短不会发生影响
            {
                while (SW3 == 0) // 如果没有抬起就等待抬起
                {
                }
                P32 = ~P32; // 抬起按键后，改变引脚信号
            }
        }
    }
}


/**
 * @description: 中断程序
 * @return {*}
 * @author: MinG
 */

void Timer0_Hander() interrupt 1
{
    // 定义静态局部变量
    static unsigned int count = 0;

    // 重新赋值脉冲计数器
    TL0 = T1MS;
    TH0 = T1MS >> 8;

    // 统计中断次数
    if (count++ >= 500) {
        LED1  = ~LED1;
        count = 0;
    }
}
