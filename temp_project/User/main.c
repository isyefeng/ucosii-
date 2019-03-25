#include "stm32f10x.h"
#include "stdio.h"
#include "LED.h"
#include "key_drive.h"
#include "EXTI_Dirve.h"		
#include "BUZ_Dirve.h"
#include "Systick_Dirve.h"
#include "TIM_Dirve.h"
#include "USART_Dirve.h"

uint32_t time;
extern unsigned int ucTemp;

/*GPIO≤‚ ‘*/
void gpio_test(void)
{
	GPIO_InitTypeDef GPIO_LED;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_LED.GPIO_Pin = GPIO_Pin_9;
	GPIO_LED.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_LED.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOB,&GPIO_LED);	
}

int main(void)
{
	unsigned char str2[]={"«Î ‰»Î“™¡¡µƒµ∆£∫¿˝»Á£∫G/R/B"};
	
	LED_R_Config();
	LED_G_Config();
	LED_G_control(0);
	LED_R_control(1);
	TIMx_config();
	
	USART_Config();
//	
	printf("%s",str2);
	gpio_test();
	GPIO_SetBits(GPIOB,GPIO_Pin_9);
	while(1)
	{
		#if 0
		if(GPIO_ReadInputDataBit(GPIO_KEY1_RORT,GPIO_KEY1_PIN))
		{
			
			while(GPIO_ReadInputDataBit(GPIO_KEY1_RORT,GPIO_KEY1_PIN));
			
			//LED_R_control(OFF);
			LED_G_TOGGLE;
		}
		#elif 0
		Pout(GPIOB_ODR_Addr,0)=1;
		Delay_ms(500);
		Pout(GPIOB_ODR_Addr,0)=0;
		Delay_ms(500);
		#elif 0
		if(Pint(GPIOB_IDR_Addr,0))
		{		
			while(Pint(GPIOB_IDR_Addr,0));
			LED_G_TOGGLE;
		}
		#elif 0
		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
//	GPIO_SetBits(GPIOA,GPIO_Pin_8);
		#elif 0
		if(time==1000)
		{
			LED_G_TOGGLE;
			time=0;
		}
		
		#elif 0
		if(time==1000)
		{
			//Usart_SendStr(USART1,str1);
			printf("%s",str2);
			time=0;
		}
		
		#else 
		
		switch(ucTemp)
		{
			case 1:LED_G_control(1);LED_R_control(0);break;
			case 2:LED_G_control(0);LED_R_control(1);break;
		}
		
		if(time==1000)
		{
			//Usart_SendStr(USART1,str1);
//			printf("%s\n",str2);
			printf("%d\n",ucTemp);
			time=0;
		}
		#endif
	}
}

