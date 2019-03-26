#ifndef __SYSTICK_DIRVE_H
#define __SYSTICK_DIRVE_H

#include "stm32f10x.h"
#include "os_cfg.h"
#include <ucos_ii.h>

#define	SYSTEM_SUPPORT_UCOS 1		//是否启用UCOS系统

void Sysclock_init(void);
void Delay_ms(uint32_t ms);

#endif /*__SYSTICK_DIRVE_H*/

