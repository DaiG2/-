/*
 * @Author: MinG
 * @Date: 2024-11-10 21:56:39
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-11 21:53:17
 * @Description: 
 * @FilePath: \¶¨Ê±Æ÷·â×°\src\main.c
 */
#include "Dir_Timer0.h"
#include <STC89C5xRC.H>

#define  LED P00
static u16 count;


void LED_Func()
{

    count++;
    if(  count >= 500)
    {
        count = 0;
        P00 = ~P00;
    }

}
void main()
{

    Dri_Timer0_Init();
    Dri_Timer0_Register(LED_Func);


    while (1)
    {
        /* code */
    }
    
}
