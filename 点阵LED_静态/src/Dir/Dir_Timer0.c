#include "Dir_Timer0.h"
#include <STC89C5xRC.H>
#include <STDIO.H>

static ptr_fun s_Timer0[4];


/**
 * @description: ��ʼ����ʱ��
 * @return {*}
 * @author: MinG
 */
void Dri_Timer0_Init()
{
    u8 i ;
    //�ж��ܿ���
    EA = 1;

    //��ʱ��0�ж�������
    ET0 = 1;

    //ѡ��ʱ���Ĺ���ģʽ������TMOD�Ĵ�������λѰַ��
    //GATE=0; ��gate = 0ʱ������ͨ���ⲿ�������ƶ�ʱ����ʼ�����жϣ���gate = 1 ʱ����
    //C/T=0�� ѡ��������Ƕ�ʱģʽ
    //M1=0�� //M1,M2��ȷ�����������ͼ�ʱ��  0��1 Ϊ16λ�Ĵ���
    //M0=1
     TMOD &= 0xF0;
     TMOD |= 0x01;

    //ȷ����ʼֵ   ���������ֵ - ��1ms*(1/������Ƶ��/��Ƶ��)��
    TL0 = 64614;
    TH0 = 64614 >> 8;

    //������ʱ��
    TR0 = 1;
    for(i = 0; i<4; i++)
    {
        s_Timer0[i] = NULL;
    }

}

/**
 * @description: ����ע�Ὣ��Ҫ��ʱ�ĺ������붨ʱ����
 * @param  ��void(*fun)() ����ָ��
 * @return  1 �ɹ����� 0 ����ʧ��
 * @author: MinG
 * 
 */
bit Dri_Timer0_Register( ptr_fun fun )
{
    u8 i;
    u8 j;

    //�ж�������û�п�λ
    for(i = 0 ;i<4;i++)
    {
        if(s_Timer0[i] == NULL)
        {
             j = i;
             break;
        }
        if(i==3)
        {
            return 0;
        }
    }

    //�ж����������Ƿ��ظ����
    for(i =0;i<=j;i++)
    {
         if(s_Timer0[i] ==fun)
         {
            return 0;
         }
         else if(i==j)
         {
            s_Timer0[i] = fun;
            return 1;
         }
    }

    return 0;
}

/**
 * @description: ɾ����ʱ����
 * @param  ��void (*fun)() ����ָ��
 * @return 1 ɾ���ɹ� 0 ɾ��ʧ��
 * @author: MinG
 */
bit Dri_Timer0_DeRegister(ptr_fun fun)
{
    u8 i;

    for( i = 0;i<4;i++)
    {
        if(s_Timer0[i] == fun)
        {
            s_Timer0[i] = NULL;
            return 1;
        }
    }
    return 0;
}


void Dri_Timer0_func () interrupt 1
{

    u8 i ;
    //����װ�ؼ�����
    TL0 = 64614;
    TH0 = 64614 >> 8;

    for( i=0;i<4;i++)
    {
        if(s_Timer0[i] != NULL)
        {
            s_Timer0[i]();
        }
    }
     
}

