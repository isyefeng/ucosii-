#include "LED.h"
#include "stm32f10x.h"

void LED_G_Config(void)
{
	GPIO_InitTypeDef GPIO_LED;
	
	RCC_APB2PeriphClockCmd(LED_G_RCC, ENABLE);
	
	GPIO_LED.GPIO_Pin = LED_G_PIN;
	GPIO_LED.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_LED.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(LED_G_RORT,&GPIO_LED);	
}

void LED_R_Config(void)
{
	GPIO_InitTypeDef GPIO_LED;
	
	RCC_APB2PeriphClockCmd(LED_R_RCC, ENABLE);
	
	GPIO_LED.GPIO_Pin = LED_R_PIN;
	GPIO_LED.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_LED.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(LED_R_RORT,&GPIO_LED);	
}

