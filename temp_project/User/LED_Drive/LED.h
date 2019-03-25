#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define 	LED_G_PIN  		GPIO_Pin_0
#define 	LED_G_RORT  	GPIOB
#define 	LED_G_RCC  		RCC_APB2Periph_GPIOB

#define 	LED_R_PIN  		GPIO_Pin_5
#define 	LED_R_RORT  	GPIOB
#define 	LED_R_RCC  		RCC_APB2Periph_GPIOB

#define   LED_G_TOGGLE   {GPIOB_ODR  ^= (unsigned int)0x0001;}

#define ON  1
#define OFF 0
#define LED_G_control(a) if(a)\
														  GPIO_ResetBits(GPIOB,GPIO_Pin_0);\
												 else GPIO_SetBits(GPIOB,GPIO_Pin_0);

#define LED_R_control(a) if(a)\
														  GPIO_ResetBits(GPIOB,GPIO_Pin_5);\
												 else GPIO_SetBits(GPIOB,GPIO_Pin_5);

void LED_G_Config(void);
void LED_R_Config(void);

//#define LED_R_RORT  GPIOB

#endif
