#include "USART_Dirve.h"
#include "stm32f10x.h"
#include "stdio.h"


void NVIC_USART_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn ;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);
}

void GPIO_config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_TX_PIN;									//TX配置推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIO_TX_RORT,&GPIO_InitStruct);	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_RX_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;			//RX配置浮空输入
	GPIO_Init(GPIO_RX_RORT,&GPIO_InitStruct);	
}

void USART_Config(void)
{
	USART_InitTypeDef USART_InitStruct;
	
	GPIO_config();
	NVIC_USART_Config();
	
	
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1, &USART_InitStruct);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);			//使能中断标志位
	USART_Cmd(USART1, ENABLE);
}

void USART_Sendbyt(USART_TypeDef* USARTx,uint16_t Data)
{
	 USART_SendData(USARTx, Data);			//发送一个字节
	 while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
}

void Usart_SendStr(USART_TypeDef* USARTx,unsigned char *Data)
{
	while(*Data!='\0')
	{
		USART_Sendbyt(USARTx,*Data);
		Data++;
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
	}
}

///重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(USART1, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		/* 等待串口输入数据 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART1);
}


