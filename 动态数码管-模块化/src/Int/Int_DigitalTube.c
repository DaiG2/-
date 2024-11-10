#include "Int_DigitalTube.h"
#define SMG_EN P36
#define LED_EN P34

static u8 s_digital_code [10] ={
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9

};

static u8 s_digital_buffer[8];//显存数组

void Int_DigitalTube_DisplaySingle(int num , int num2) //
{
     P0 = 0;
     P1 &=0xC7;
     P1 |= (num-1 << 3);
     P0 = s_digital_buffer[num2];
}

void Int_DigitalTube_dispalyNum(long num)
{
     int i = 0;
    int j = 7;
    for(i = 0;i<=7;i++)
    {
        s_digital_buffer[i] = 0;
    }
    if(num ==0 )
    {
        Int_DigitalTube_DisplaySingle(7,0);
        return;
    }
    else
    {
        while(num !=0)
        {
         s_digital_buffer[j]= s_digital_code[num % 10];
         num /= 10;
         j-- ;
        }
        
    }
}

void Int_DigitalTube_Dispaly()
{
    
    int i = 0;
    P0 = 0; //消除上一次显示的重影
    for(i = 0 ;i<=7 ;i++)
    {
        Int_DigitalTube_DisplaySingle(i+1,i);
        Delay1ms(1);
    }
}

void Int_DigitalTube_EN()
{
    SMG_EN = 0; //数字管显示开关 0 开 ，1 关
    LED_EN = 0; //LED流水灯开关 0 关 ，1 开；
}
