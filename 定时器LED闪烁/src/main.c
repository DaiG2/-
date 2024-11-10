/*
 * @Author: MinG
 * @Date: 2024-11-08 21:20:07
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-10 21:55:27
 * @Description: 
 * @FilePath: \��ʱ��LED��˸\src\main.c
 */
#include <STC89C5xRC.H>
#include "Com_Util.h"
#include "Dri_Timer0.h"
#define T1MS (65536 - FOSC / NT / 1000) // 1MS����ʱ��12Tģʽ��
#define SW3  P43
#define LED1 P00

/**
 * @description: ͨ������SW3��������ʱ��
 * @return {*}
 * @author: MinG
 */
void main()
{
    Timer0_Init();
    while (1) {
        if (SW3 == 0) // �ȼ�ⰴ���Ƿ񱻰���
        {
            Delay1ms(10); // ���°������ӳ�10ms������ǰ�ض�����
            if (SW3 == 0) // �ٴ��жϰ����Ƿ�̧�����̧�������Ϊʱ��̫�̲��ᷢ��Ӱ��
            {
                while (SW3 == 0) // ���û��̧��͵ȴ�̧��
                {
                }
                P32 = ~P32; // ̧�𰴼��󣬸ı������ź�
            }
        }
    }
}


/**
 * @description: �жϳ���
 * @return {*}
 * @author: MinG
 */

void Timer0_Hander() interrupt 1
{
    // ���徲̬�ֲ�����
    static unsigned int count = 0;

    // ���¸�ֵ���������
    TL0 = T1MS;
    TH0 = T1MS >> 8;

    // ͳ���жϴ���
    if (count++ >= 500) {
        LED1  = ~LED1;
        count = 0;
    }
}
