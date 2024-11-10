#include "Int_Buzzer.h"
#include "Com_Util.h"

void Int_Buzzer_Buzz()
{
    u8 count = 100;

    while(count)
    {
        BUZZ = ~BUZZ;
        Delay1ms(1);
        count--;
    }

}