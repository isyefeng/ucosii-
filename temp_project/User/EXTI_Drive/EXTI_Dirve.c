#include "EXTI_Dirve.h"
#include "stm32f10x.h"

void NVIC_Init_config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_SURFACE_0;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = HOST;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = SON;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);
}

void EXTI_GPIO_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
	GPIO_EXTILineConfig(EXTILine_GPIOA,EXTI_GPIO_Line_0);
	NVIC_Init_config();
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line_0 ;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising ;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStruct);
}
