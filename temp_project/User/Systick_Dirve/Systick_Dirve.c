#include "Systick_Dirve.h"
#include "stm32f10x.h"

void Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	for(i=0;i<ms;i++)
	{
		while(!((SysTick->CTRL)&(1<<16)));
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
