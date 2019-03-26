#include "includes.h"

uint32_t time;
extern unsigned int ucTemp;

#define	START_STK_SIZE	128
#define	START_TASK_PRIO 3
OS_STK START_TASK_STK[START_STK_SIZE] = {0,};
void start_task(void* arg);

#define LED0_TASK_PRIO			4
#define LED0_STK_SIZE			128
OS_STK LED0_TASK_STK[LED0_STK_SIZE];
void led0_task(void* arg);

#define LED1_TASK_PRIO			5
#define LED1_STK_SIZE			128
OS_STK LED1_TASK_STK[LED1_STK_SIZE];
void led1_task(void* arg);

void Global_drv_init(void)
{
	Sysclock_init();
	LED_G_Config();
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
	OSStatInit();  //开启统计任务
	
	OS_ENTER_CRITICAL();  //进入临界区(关闭中断)
	OSTaskCreate(led0_task,(void*)0,(OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1],LED0_TASK_PRIO);//创建LED0任务
	OSTaskSuspend(START_TASK_PRIO);//挂起开始任务
	OS_EXIT_CRITICAL();  //退出临界区(开中断)
}

void led0_task(void* arg)
{
	while(1)
	{
		LED_G_TOGGLE;
		OSTimeDly(10);
		LED_G_TOGGLE;
		OSTimeDly(10);
	}
}

void led1_task(void* arg)
{
	while(1)
	{
		LED_R_control(1);
		OSTimeDly(10);
		LED_R_control(0);
		OSTimeDly(10);
	}
}

