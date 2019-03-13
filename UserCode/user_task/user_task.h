#ifndef __USER_TASK_H
#define __USER_TASK_H

#include "define_all.h"  
#include <string.h>

#include "FreeRTOS.h"
#include "projdefs.h"
#include "portable.h"
#include "task.h"
#include "queue.h"



void TASK_LED1_Blinky(void *gh);
void TASK_LED2_Blinky(void *gh);

#endif /* __TASK_H */
