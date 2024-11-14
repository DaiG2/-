#include "Dir_Timer0.h"
#include <STC89C5xRC.H>
#include <STDIO.H>

static ptr_fun s_Timer0[4];


/**
 * @description: 初始化定时器
 * @return {*}
 * @author: MinG
 */
void Dri_Timer0_Init()
{
    u8 i ;
    //中断总开关
    EA = 1;

    //定时器0中断允许开关
    ET0 = 1;

    //选择定时器的工作模式（由于TMOD寄存器不可位寻址）
    //GATE=0; 当gate = 0时，不能通过外部按键控制定时器开始还是中断，则gate = 1 时允许
    //C/T=0； 选择计数还是定时模式
    //M1=0， //M1,M2来确定是哪种类型计时器  0，1 为16位寄存器
    //M0=1
     TMOD &= 0xF0;
     TMOD |= 0x01;

    //确定初始值   计数器最大值 - （1ms*(1/（晶振频率/分频）)）
    TL0 = 64614;
    TH0 = 64614 >> 8;

    //启动定时器
    TR0 = 1;
    for(i = 0; i<4; i++)
    {
        s_Timer0[i] = NULL;
    }

}

/**
 * @description: 函数注册将需要定时的函数加入定时数组
 * @param  ：void(*fun)() 函数指针
 * @return  1 成功加入 0 加入失败
 * @author: MinG
 * 
 */
bit Dri_Timer0_Register( ptr_fun fun )
{
    u8 i;
    u8 j;

    //判断里面有没有空位
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

    //判断数组里面是否重复添加
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
 * @description: 删除定时任务
 * @param  ：void (*fun)() 函数指针
 * @return 1 删除成功 0 删除失败
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
    //重新装载计数器
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

