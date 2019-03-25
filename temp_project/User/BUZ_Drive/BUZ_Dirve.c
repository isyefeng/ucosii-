#include "BUZ_Dirve.h"
#include "stm32f10x.h"

void BUZ_config(void)
{
	GPIO_InitTypeDef GPIO_BUZ;
	
	RCC_APB2PeriphClockCmd(BUZ_RCC, ENABLE);
	
	GPIO_BUZ.GPIO_Pin = BUZ_PIN;
	GPIO_BUZ.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_BUZ.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(BUZ_RORT,&GPIO_BUZ);	
}
