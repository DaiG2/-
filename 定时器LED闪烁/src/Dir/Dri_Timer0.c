#include "Dri_Timer0.h"
#define T1MS (65536 - FOSC / NT / 1000)
void Timer0_Init()
{
    // �ж��ܿ���
    EA = 1;

    // ��ʱ��0����
    ET0 = 1;

    // ��ʱ��������ʽ
    TMOD &= 0xF0;
    TMOD |= 0x09;

    // ���ü����������ʼֵ
    TL0 = T1MS;
    TH0 = T1MS >> 8;

    // ������ʱ��
    TR0 = 1;
    P32 = 0;

}