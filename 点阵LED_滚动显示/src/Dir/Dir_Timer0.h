#ifndef __DIR_TIMER0_H__
#define __DIR_TIMER0_H__

#include "Com_Util.h"

typedef void (*ptr_fun)();

void Dri_Timer0_Init();

bit Dri_Timer0_Register( ptr_fun fun);

bit Dri_Timer0_DeRegister( ptr_fun fun);




#endif /* __DIR_TIMER0_H__ */