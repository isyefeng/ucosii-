#ifndef __GLOBAL_DRV_H__
#define	__GLOBAL_DRV_H__

#include "includes.h"

/***************************************************
*			蜂鸣器驱动
***************************************************/

#define BUZ_PIN		GPIO_Pin_8
#define BUZ_RORT  GPIOA
#define BUZ_RCC  	RCC_APB2Periph_GPIOA

void BUZ_config(void);


/***************************************************
*			中断
***************************************************/

#define EXTI_SURFACE_0  EXTI0_IRQn

#define EXTILine_GPIOA		GPIO_PortSourceGPIOA
#define EXTI_GPIO_Line_0 	GPIO_PinSource0
#define EXTI_Line_0       EXTI_Line0


#define HOST    1    //主优先级
#define SON     1		 //子优先级

void EXTI_GPIO_Init(void);

/***************************************************
*			按键
***************************************************/
#define GPIO_KEY1_PIN  GPIO_Pin_0
#define GPIO_KEY1_RORT GPIOA
#define GPIO_KEY1_RCC  RCC_APB2Periph_GPIOA

#define KEY_ON  1
#define KEY_OFF 0

void Key1_Init(void);

/***************************************************
*			定时器
***************************************************/
#define USE_TIM7 0

#if	!USE_TIM7
#define		TIM_X									TIM6
#define 	RCC_TIMx 							RCC_APB1Periph_TIM6
#define   TIMX_IRQn							TIM6_IRQn
#else
#define		TIM_X									TIM7
#define 	RCC_TIMx 							RCC_APB1Periph_TIM7
#define   TIMX_IRQn							TIM7_IRQn
#endif

#define		RCC_TIM_Prescaler			71
#define   RCC_TIM_Period				(1000-1)

void TIMx_config(void);

/***************************************************
*			LED
***************************************************/
#define 	LED_G_PIN  		GPIO_Pin_0
#define 	LED_G_RORT  	GPIOB
#define 	LED_G_RCC  		RCC_APB2Periph_GPIOB

#define 	LED_R_PIN  		GPIO_Pin_5
#define 	LED_R_RORT  	GPIOB
#define 	LED_R_RCC  		RCC_APB2Periph_GPIOB

#define   LED_G_TOGGLE   {GPIOB_ODR  ^= (unsigned int)0x0001;}
#define   LED_R_TOGGLE   {GPIOB_ODR  ^= (unsigned int)0x0020;}

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

/***************************************************
*			系统
***************************************************/
#define	SYSTEM_SUPPORT_UCOS 1		//是否启用UCOS系统

void Sysclock_init(void);
void Delay_ms(uint32_t ms);

/***************************************************
*			串口
***************************************************/
#define		GPIO_TX_PIN		GPIO_Pin_9
#define		GPIO_RX_PIN		GPIO_Pin_10
#define		GPIO_TX_RORT	GPIOA
#define		GPIO_RX_RORT	GPIOA

void USART_Config(void);
void USART_Sendbyt(USART_TypeDef* USARTx,uint16_t Data);
void Usart_SendStr(USART_TypeDef* USARTx,unsigned char * Data);

/***************************************************
*			按键
***************************************************/


/***************************************************
*			按键
***************************************************/

#endif
