#include "key_drive.h"
#include "stm32f10x.h"

void Key1_Init(void)
{
	GPIO_InitTypeDef KEY1_Initstruct;
	
	RCC_APB2PeriphClockCmd(GPIO_KEY1_RCC, ENABLE);
	
	KEY1_Initstruct.GPIO_Pin = GPIO_KEY1_PIN;
	KEY1_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(GPIO_KEY1_RORT,&KEY1_Initstruct);	
}
