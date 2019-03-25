#ifndef __EXTI_DIRVE_H
#define __EXTI_DIRVE_H

#define EXTI_SURFACE_0  EXTI0_IRQn

#define EXTILine_GPIOA		GPIO_PortSourceGPIOA
#define EXTI_GPIO_Line_0 	GPIO_PinSource0
#define EXTI_Line_0       EXTI_Line0


#define HOST    1    //主优先级
#define SON     1		 //子优先级

void EXTI_GPIO_Init(void);

#endif /*__EXIT_DIRVE_H*/
