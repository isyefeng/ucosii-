#ifndef __USART_DIRVE_H
#define __USART_DIRVE_H

#include "stm32f10x_usart.h"
#include "stm32f10x.h"

#define		GPIO_TX_PIN		GPIO_Pin_9
#define		GPIO_RX_PIN		GPIO_Pin_10
#define		GPIO_TX_RORT	GPIOA
#define		GPIO_RX_RORT	GPIOA

void USART_Config(void);
void USART_Sendbyt(USART_TypeDef* USARTx,uint16_t Data);
void Usart_SendStr(USART_TypeDef* USARTx,unsigned char * Data);

#endif /*__USART_DIRVE_H*/
