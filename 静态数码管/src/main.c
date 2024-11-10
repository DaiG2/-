#include <STC89C5xRC.H>
#include <INTRINS.H>

#define SMG_EN P36
#define LED_EN P34
typedef unsigned char u8;
typedef unsigned int u16;

static u8 digital_code [10] ={
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

void DigitalTube_DisplaySingle(int num , int num2) //
{
     P0 = 0;
     P1 &=0xC7;
     P1 |= (num-1 << 3);
     P0 = s_digital_buffer[num2];
}


void  DigitalTube_dispalyNum( long num)  //输入的数字
{
        int i = 0;
        int j = 7;
        for(i = 0;i<=7;i++)
        {
            s_digital_buffer[i] = 0;
        }
        if(num ==0 )
        {
            DigitalTube_DisplaySingle(7,0);
            return;
        }
        else
        {
            while(num !=0)
            {
            s_digital_buffer[j]= digital_code[num % 10];
            num /= 10;
            j-- ;
            }
            
        }
}
void Delay1ms(u16 count) //@11.0592MHz
{
    u8 i, j;

    while (count > 0)
    {
        count--;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}
void DigitalTube_Dispaly()
{
    int i = 0;
    SMG_EN = 0; //数字管显示开关 0 开 ，1 关
    for(i = 0 ;i<=7 ;i++)
    {
        DigitalTube_DisplaySingle(i+1,i);
        Delay1ms(1);
    }
   
}



/*
   动态数码管：先通过 DigitalTube_dispalyNum函数对输入的数字进行处理：
   将每位的数字编码存入显存数组，通过数字编码数组将对应的16进制的编码存入显存数组
   然后调用DigitalTube_DisplaySingle函数分别每一位的数字显示出来，最后DigitalTube_Dispaly函数
   for循环将数字显示；
 */
void main()
{  
    LED_EN = 0; //LED流水灯开关 0 关 ，1 开；
    DigitalTube_dispalyNum(12345678);
    while(1)
   {
     P0 = 0; 
     DigitalTube_Dispaly();
   }
}