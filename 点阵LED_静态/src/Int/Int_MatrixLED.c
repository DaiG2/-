/*
 * @Author: MinG
 * @Date: 2024-11-12 16:56:27
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-12 18:04:04
 * @Description:
 * @FilePath: \静态点阵LED\src\Int\Int_MatrixLED.c
 */
#include "Int_MatrixLED.h"
#include <STC89C5xRC.H>

#define LEDMatrix_EN P35
#define LED_EN       P34
#define SER          P10 // 串行输入
#define RCK          P11 // 并行输出时钟
#define SCK          P12 // 串行输入时钟

static u8 buffer_arry[8];

void Int_MatrixLED_Init()
{

    LEDMatrix_EN = 0; // 点阵LED开关

    LED_EN = 0; // 流水灯开关
}

void Int_MatrixLED_Set(u8 pic[])
{
    u8 i;
    for (i = 0; i < 8; i++) {
        buffer_arry[i] = pic[i];
    }
}

void Int_MatrixLED_Refresh()
{
    u8 i;
    for (i = 0; i < 8; i++) {

        P0 = 0xFF; // 清空上次显示，为了防止重影
        if (i == 0) {
            SER = 1;
        } else {
            SER = 0;
        }

        // 给一个上升电压将SER数字放入到移位寄存器
        SCK = 0;
        SCK = 1;

        // 给上升电压将移位寄存器的数据放入存储寄存器
        RCK = 0;
        RCK = 1;

        // 控制列
        P0 = ~buffer_arry[i];

        Delay1ms(1); // 为了使亮度一直如果不加会出现最后一个LED比前亮
    }
}

void Int_MatrixLED_Timer0()
{
   
    u8 i;
    P0 = 0xFF;
    if (i == 0) {
        SER = 1;
    } else {
        SER = 0;
    }

    SCK = 0;
    SCK = 1;

    RCK = 0;
    RCK = 1;

    P0 = ~buffer_arry[i];

    i++;

    if (i == 8) {
        i = 0;
    }
}
