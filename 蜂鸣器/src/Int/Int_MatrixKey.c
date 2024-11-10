#include "Int_MatrixKey.h"
#include <STC89C5xRC.H>
u8 MatrixKeyChecks()
{


   
//检测第一行
    P2 = 0xFE;
    {
        if (P24 == 0)
        {
            Delay1ms(10);
            while(P24 == 0);
            return 6;
        }
        if (P25 == 0)
        {
            Delay1ms(10);
            while(P25 == 0);
            return 7;
        }
        if (P26 == 0)
        {
            Delay1ms(10);
            while(P26 == 0);
            return 8;
        }
        if (P27 == 0)
        {
            Delay1ms(10);
            while(P27 == 0);
            return 9;
        }
        
    }

    //检测第二行
    P2 = 0xFD;
    {
        if (P24 == 0)
        {
            Delay1ms(10);
            while(P24 == 0);
            return 10;
        }
        if (P25 == 0)
        {
            Delay1ms(10);
            while(P25 == 0);
            return 11;
        }
        if (P26 == 0)
        {
            Delay1ms(10);
            while(P26 == 0);
            return 12;
        }
        if (P27 == 0)
        {
            Delay1ms(10);
            while(P27 == 0);
            return 13;
        }
        
    }
    //检测第三行
        P2 = 0xFB;
    {
        if (P24 == 0)
        {
            Delay1ms(10);
            while(P24 == 0);
            return 14;
        }
        if (P25 == 0)
        {
            Delay1ms(10);
            while(P25 == 0);
            return 15;
        }
        if (P26 == 0)
        {
            Delay1ms(10);
            while(P26 == 0);
            return 16;
        }
        if (P27 == 0)
        {
            Delay1ms(10);
            while(P27 == 0);
            return 17;
        }
        
    }

    //检测第四行
        P2 = 0xF7;
    {
        if (P24 == 0)
        {
            Delay1ms(10);
            while(P24 == 0);
            return 18;
        }
        if (P25 == 0)
        {
            Delay1ms(10);
            while(P25 == 0);
            return 19;
        }
        if (P26 == 0)
        {
            Delay1ms(10);
            while(P26 == 0);
            return 20;
        }
        if (P27 == 0)
        {
            Delay1ms(10);
            while(P27 == 0);
            return 21;
        }
        
    }
    
    return 0;
}