#ifndef __KEY_DRIVE_H
#define __KEY_DRIVE_H

#define GPIO_KEY1_PIN  GPIO_Pin_0
#define GPIO_KEY1_RORT GPIOA
#define GPIO_KEY1_RCC  RCC_APB2Periph_GPIOA

#define KEY_ON  1
#define KEY_OFF 0

void Key1_Init(void);

#endif /*__KEY_DRIVE_H*/
