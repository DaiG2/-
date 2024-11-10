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

static u8 s_digital_buffer[8];//�Դ�����

void DigitalTube_DisplaySingle(int num , int num2) //
{
     P0 = 0;
     P1 &=0xC7;
     P1 |= (num-1 << 3);
     P0 = s_digital_buffer[num2];
}


void  DigitalTube_dispalyNum( long num)  //���������
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
    SMG_EN = 0; //���ֹ���ʾ���� 0 �� ��1 ��
    for(i = 0 ;i<=7 ;i++)
    {
        DigitalTube_DisplaySingle(i+1,i);
        Delay1ms(1);
    }
   
}



/*
   ��̬����ܣ���ͨ�� DigitalTube_dispalyNum��������������ֽ��д���
   ��ÿλ�����ֱ�������Դ����飬ͨ�����ֱ������齫��Ӧ��16���Ƶı�������Դ�����
   Ȼ�����DigitalTube_DisplaySingle�����ֱ�ÿһλ��������ʾ���������DigitalTube_Dispaly����
   forѭ����������ʾ��
 */
void main()
{  
    LED_EN = 0; //LED��ˮ�ƿ��� 0 �� ��1 ����
    DigitalTube_dispalyNum(12345678);
    while(1)
   {
     P0 = 0; 
     DigitalTube_Dispaly();
   }
}