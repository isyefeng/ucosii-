#include "includes.h"

uint32_t time;
extern unsigned int ucTemp;

#define	START_STK_SIZE	1024
#define	START_TASK_PRIO 3
OS_STK START_TASK_STK[START_STK_SIZE] = {0,};
void start_task(void* arg);

//LED0����
//�����������ȼ�
#define LED0_TASK_PRIO			7
//���������ջ��С
#define LED0_STK_SIZE			128
//�����ջ
OS_STK LED0_TASK_STK[LED0_STK_SIZE];
//������
void led0_task(void* arg);

void Global_drv_init(void)
{
	Sysclock_init();
}

int main(void)
{
	Global_drv_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	OSInit(); 
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO); 
	OSStart(); 
}

void start_task(void* arg)
{
	OS_CPU_SR cpu_sr=0;
	arg=arg;
	OSStatInit();  //����ͳ������
	
	OS_ENTER_CRITICAL();  //�����ٽ���(�ر��ж�)
	OSTaskCreate(led0_task,(void*)0,(OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1],LED0_TASK_PRIO);//����LED0����
//	OSTaskCreate(led1_task,(void*)0,(OS_STK*)&LED1_TASK_STK[LED1_STK_SIZE-1],LED1_TASK_PRIO);//����LED1����
//	OSTaskCreate(float_task,(void*)0,(OS_STK*)&FLOAT_TASK_STK[FLOAT_STK_SIZE-1],FLOAT_TASK_PRIO);//���������������
	OSTaskSuspend(START_TASK_PRIO);//����ʼ����
	OS_EXIT_CRITICAL();  //�˳��ٽ���(���ж�)
}

void led0_task(void* arg)
{
	while(1)
	{
		
	}
}

