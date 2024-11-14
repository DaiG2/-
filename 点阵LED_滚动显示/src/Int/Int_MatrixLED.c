/*
 * @Author: MinG
 * @Date: 2024-11-12 16:56:27
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-14 12:23:16
 * @Description:
 * @FilePath: \����LED_������ʾ\src\Int\Int_MatrixLED.c
 */
#include "Int_MatrixLED.h"
#include "Dir_Timer0.h"
#include <STC89C5xRC.H>

#define LEDMatrix_EN P35
#define LED_EN       P34
#define SER          P10 // ��������
#define RCK          P11 // �������ʱ��
#define SCK          P12 // ��������ʱ��

static u8 buffer_arry[8];
static u8 c =0;

void Int_MatrixLED_Init()
{
    u8 i;

    

    LEDMatrix_EN = 0; // ����LED����

    LED_EN = 0; // ��ˮ�ƿ���
    for(i = 0 ;i<8;i++)
    {
        buffer_arry[i] = 0;
    }

     Dri_Timer0_Register(Int_MatrixLED_Timer0);
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

        P0 = 0xFF; // ����ϴ���ʾ��Ϊ�˷�ֹ��Ӱ
        if (i == 0) {
            SER = 1;
        } else {
            SER = 0;
        }

        // ��һ��������ѹ��SER���ַ��뵽��λ�Ĵ���
        SCK = 0;
        SCK = 1;

        // ��������ѹ����λ�Ĵ��������ݷ���洢�Ĵ���
        RCK = 0;
        RCK = 1;

        // ������
        P0 = ~buffer_arry[i];

        Delay1ms(1); // Ϊ��ʹ����һֱ������ӻ�������һ��LED��ǰ��
    }
}

void Int_MatrixLED_Timer0()
{
   
   
    P0 = 0xFF;
    if (c == 0) {
        SER = 1;
    } else {
        SER = 0;
    }

    SCK = 0;
    SCK = 1;

    RCK = 0;
    RCK = 1;

    P0 = ~buffer_arry[c];

    c++;

    if (c == 8) {
        c = 0;
    }
}

void Int_MatrixLED_shift(u8 pic)
{
    u8 i;

    for(i =7;i>=1;i--)
    {
        buffer_arry[i] = buffer_arry[i-1];
    }

    buffer_arry[0] = pic;
}
