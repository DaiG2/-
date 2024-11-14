/*
 * @Author: MinG
 * @Date: 2024-11-12 16:55:17
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-12 18:02:53
 * @Description: 
 * @FilePath: \æ≤Ã¨µ„’ÛLED\src\main.c
 */
#include "Int_MatrixLED.h"
#include "Dir_Timer0.h"

void main()
{
    u8 pic[] ={
                 0x01,
                 0x02,
                 0x04,
                 0x08,
                 0x10,
                 0x20,
                 0x40,
                 0x80
    };
    Int_MatrixLED_Init();
    Dri_Timer0_Init();
    Int_MatrixLED_Set(pic);
    Dri_Timer0_Register(Int_MatrixLED_Timer0);
    while (1)
    {
       
    }
    
}
