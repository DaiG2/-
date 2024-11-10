#include "Int_Buzzer.h"
#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"

void main()
{
    u8 key ;
    Int_DigitalTube_EN(); //数码管开关
    while (1)
    {
        key = MatrixKeyChecks();  //按键返回的数字
        if(key)
        {
            Int_DigitalTube_dispalyNum( key);  //数码管显示按键返回的数字
            Int_Buzzer_Buzz();  //蜂鸣器启动
        }
         Int_DigitalTube_Dispaly();  //数码管开始显示
    }
    
}
