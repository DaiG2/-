#include "Int_Buzzer.h"
#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"

void main()
{
    u8 key ;
    Int_DigitalTube_EN(); //����ܿ���
    while (1)
    {
        key = MatrixKeyChecks();  //�������ص�����
        if(key)
        {
            Int_DigitalTube_dispalyNum( key);  //�������ʾ�������ص�����
            Int_Buzzer_Buzz();  //����������
        }
         Int_DigitalTube_Dispaly();  //����ܿ�ʼ��ʾ
    }
    
}
