#ifndef  __TIM_DIRVE_H
#define  __TIM_DIRVE_H

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

#endif  /*__TIM_DIRVE_H*/
