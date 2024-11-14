/*
 * @Author: MinG
 * @Date: 2024-11-12 16:56:27
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-12 18:04:04
 * @Description:
 * @FilePath: \��̬����LED\src\Int\Int_MatrixLED.c
 */
#include "Int_MatrixLED.h"
#include <STC89C5xRC.H>

#define LEDMatrix_EN P35
#define LED_EN       P34
#define SER          P10 // ��������
#define RCK          P11 // �������ʱ��
#define SCK          P12 // ��������ʱ��

static u8 buffer_arry[8];

void Int_MatrixLED_Init()
{

    LEDMatrix_EN = 0; // ����LED����

    LED_EN = 0; // ��ˮ�ƿ���
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
