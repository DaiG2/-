/*
 * @Author: MinG
 * @Date: 2024-11-12 18:51:02
 * @LastEditors: Do not edit
 * @LastEditTime: 2024-11-14 12:34:36
 * @Description: 
 * @FilePath: \µ„’ÛLED_πˆ∂Øœ‘ æ\src\main.c
 */
#include "Int_MatrixLED.h"
#include "Dir_Timer0.h"

u8 picture[26] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
                  0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
                  0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
                  0x0A, 0x14};

void main()
{


    Dri_Timer0_Init();
    Int_MatrixLED_Init();
    while (1)
    {
        u8 i;

        for(i =0 ;i<26;i++)
        {
            Int_MatrixLED_shift(picture[i]);
            Delay1ms(200);
        }

   
    }
    
}
