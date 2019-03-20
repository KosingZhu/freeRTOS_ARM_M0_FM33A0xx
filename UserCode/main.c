/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/******************************************************************************
 * This project provides two demo applications.  A simple blinky style project,
 * and a more comprehensive test and demo application.  The
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting (defined in this file) is used to
 * select between the two.  The simply blinky demo is implemented and described
 * in main_blinky.c.  The more comprehensive test and demo application is
 * implemented and described in main_full.c.
 *
 * This file implements the code that is not demo specific, including the
 * hardware setup and FreeRTOS hook functions.  It also contains a dummy
 * interrupt service routine called Dummy_IRQHandler() that is provided as an
 * example of how to use interrupt safe FreeRTOS API functions (those that end
 * in "FromISR").
 *
 *****************************************************************************/


/* Standard includes. */
#include "string.h"
#include <stdarg.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "event_groups.h"
#include "stream_buffer.h"
#include "message_buffer.h"
#include "croutine.h"

/* Demo application include. */
#include "define_all.h"  
#include "user_task.h"
#include "timers.h"
#include "general.h"


/* Set mainCREATE_SIMPLE_BLINKY_DEMO_ONLY to one to run the simple blinky demo,
or 0 to run the more comprehensive test and demo application. */
#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY	1


/*-----------------------------------------------------------*/




/*
 * CMSIS clock configuration function.
 */
extern void SystemCoreClockUpdate( void );

/*-----------------------------------------------------------*/

QueueHandle_t xQueue1 = NULL, xQueue2 = NULL;
QueueSetHandle_t xQueueSet = NULL;
BaseType_t ret;
extern uint08 string[PRINT_LEN];

QueueHandle_t xIntegerQueue;
EventGroupHandle_t xEventGroup;



SemaphoreHandle_t printMutex;
uint32 myprintf(uint08 *format, ...)
{	
	va_list Argument;
	uint32 slen;
		
	va_start(Argument, format);
taskENTER_CRITICAL();
	//xSemaphoreTake(printMutex, portMAX_DELAY);
	//vTaskSuspendAll();

	_vsnprintf(string, sizeof(string), format, Argument);
	va_end(Argument);
	slen = strlen(string);
	uart_send(PRINTF_UART, string, slen);

taskEXIT_CRITICAL();
	//xSemaphoreGive(printMutex);
	//xTaskResumeAll();

	return slen;
}



void oneShot( TimerHandle_t xTimer )
{
	sprintf(string, "say hello oneshot\n");
	uart_send(PRINTF_UART, string, strlen(string));
	
}


void autoReload(TimerHandle_t xtimer)
{
	static uint08 cnt = 0;

	cnt = (uint08)pvTimerGetTimerID(xtimer);
	vTimerSetTimerID(xtimer, (void*)++cnt);
	sprintf(string, "say hello AutoReload cnt:%d\n", cnt);
	uart_send(PRINTF_UART, string, strlen(string));
	if(cnt == 5)
	{
		xTimerChangePeriod(xtimer, pdMS_TO_TICKS(200), 0);
	}
	else if(cnt == 10)
	{
		xTimerStop(xtimer, 0);
	sprintf(string, "stop timer\n");
	uart_send(PRINTF_UART, string, strlen(string));		
	}
	
}


void interruptHandle(void* para1, uint32_t para2)
{
	//sprintf(string, "say in handle:%d\n", para2);
	//uart_send(PRINTF_UART, string, strlen(string));
	

	return;
}


extern void vhandleTask(void *P);
extern void vPeriodicTask(void *P);
SemaphoreHandle_t semaphore; 
BaseType_t xHigherPriorityTaskWoken = pdFALSE;


#define task1bit	(0x01<<0)
#define task2bit	(0x01<<1)
#define task3bit 	(0x01<<2)


void vhandleTask(void *p)
{
	uint08 cnt = 0;
	uint32_t value;
	uint32 maskbit = (task1bit|task2bit|task3bit);
	UBaseType_t taskNum;
	TaskStatus_t taskArr[10];
	uint32_t pulTotalRunTime;
	uint08 str[30];
		
	for(;;)
	{
		IWDT_Clr();


		value = xMessageBufferReceive((MessageBufferHandle_t)*(MessageBufferHandle_t**)p, str, sizeof(str), portMAX_DELAY);
		myprintf("p:0x%p, value:%d, str:%s\n", p, value, str);
		
/*	
		taskNum = uxTaskGetNumberOfTasks();
		myprintf("taskNum:%d\n", taskNum);

		taskNum = uxTaskGetSystemState(taskArr, 10, &pulTotalRunTime);
		myprintf("TRunTime:%d\n", pulTotalRunTime);
		if(taskNum != 0)
		{
			for(uint08 i = 0; i < taskNum; i++)
			{
				myprintf("stackBase:0x%p, handle:0x%p,name:%s,runtime:%d,priority:%d, curPr:%d, state:%d,reS:%d\n",\
	taskArr[i].pxStackBase, taskArr[i].xHandle, taskArr[i].pcTaskName, taskArr[i].ulRunTimeCounter, taskArr[i].uxBasePriority,\
	taskArr[i].uxCurrentPriority, taskArr[i].eCurrentState,  taskArr[i].usStackHighWaterMark\
						);
			}			
		}

		value = ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
		if(value != 0)
		{
			myprintf("get value:%d\n", value);
		}
		//vTaskDelay(pdMS_TO_TICKS(500));

	
		myprintf("\n-------------read bit start----------------\n");
		value = xEventGroupWaitBits(xEventGroup, maskbit, pdTRUE, pdTRUE, portMAX_DELAY);

		if(value&task1bit)
		{
			myprintf("task1 happen:%d\n", value);
		}

		if(value&task2bit)
		{
			myprintf("task2 happen:%d\n", value);			
		}

		if(value&task3bit)
		{
			myprintf("task3 happen:%d\n", value);
		}
*/		
		//myprintf("\n-------------read bit end----------------\n");

		//xSemaphoreTake(semaphore, portMAX_DELAY);
		//cnt = uxSemaphoreGetCount(semaphore);
		
		//cnt = xQueueReceive(xIntegerQueue, &value, 0);
		//if(cnt != errQUEUE_EMPTY)
		//{
		//taskENTER_CRITICAL();
		//sprintf(string, "catch a interupt:%d\n", value);
		//uart_send(PRINTF_UART, string, strlen(string));
		//taskEXIT_CRITICAL();
		//myprintf("catch a interupt:%d\n", (uint32)p);
		//}
		//LED_TOG;
		//vTaskDelay(pdMS_TO_TICKS(100));
	}
	return;
}



void vPeriodicTask(void *p)
{
	EventBits_t ret;
	uint08 *str = "hello world!";
	uint08 len;

	for(;;)
	{
		IWDT_Clr();

		len = xMessageBufferSend((MessageBufferHandle_t)*(MessageBufferHandle_t**)p, str, strlen(str)+1, 0);
		myprintf("send p:0x%p, len:%d--%s\n", p, len, str);

		//xTaskNotifyGive((TaskHandle_t)p);

		//myprintf("\n-------------set bit start-------------------\n");
		//xEventGroupSync(xEventGroup, (task1bit|task2bit), (task1bit|task2bit|task3bit), portMAX_DELAY);

		//ret = xEventGroupSetBits( xEventGroup,  task1bit);
		//myprintf("set bit1:%d\n", ret);

		//ret = xEventGroupSetBits(xEventGroup, task2bit);
		//myprintf("set bit2:%d\n", ret);
		
		//sprintf(string, "i just output\n");
		//uart_send(PRINTF_UART, string, strlen(string));
		//myprintf("\n-------------set bit end-------------------\n");

		//TicksDelayMs( 200, NULL );//软件延时		
		 //vTaskDelay(pdMS_TO_TICKS(300));	
	}
	
	return;
}

void coFun(CoRoutineHandle_t coHandle, UBaseType_t arg)
{
	crSTART(coHandle);
	for(;;)
	{
		LED_TOG;
		crDELAY(coHandle, pdMS_TO_TICKS(300));
	}
	crEND();
}


void coFun1(CoRoutineHandle_t coHandle, UBaseType_t arg)
{
	crSTART(coHandle);
	for(;;)
	{
		LED0_TOG;
		crDELAY(coHandle, pdMS_TO_TICKS(300));
	}
	crEND();
}




int main( void )
{
	uint32 flag;
	TaskHandle_t taskH;
	StreamBufferHandle_t buff;
	MessageBufferHandle_t mes;

	/* Prepare the hardware to run this demo. */
	IWDT_Clr();
	Init_System();			//系统初始化 


	xCoRoutineCreate(coFun, 0, 0);
	xCoRoutineCreate(coFun1, 0, 0);


#if 0	

	//semaphore = xSemaphoreCreateBinary();
	//semaphore = xSemaphoreCreateCounting(5, 0);
	//printMutex = xSemaphoreCreateMutex();
	//xIntegerQueue = xQueueCreate( 100, sizeof(uint32_t) );
	//xEventGroup = xEventGroupCreate();


	//buff = xStreamBufferCreate(20, 0);
	mes = xMessageBufferCreate(20);

	if(mes != NULL)
	{
		myprintf("mes:%p\n", mes);
	}

	flag = readRSTFLAG();
	sprintf(string, "flag:%d\n", flag);
	uart_send(PRINTF_UART, string, strlen(string));
	clrRSFLAG(0);

	myprintf("%s,%d\n", __FILE__, __LINE__);

	//if(semaphore != NULL)
	{
		//xTaskCreate(vPeriodicTask,   "Periodic2", 100, (void*)taskH, 3, NULL );
		xTaskCreate(vhandleTask,   "Handler", 400, (void*)&mes, 3, &taskH );
		xTaskCreate(vPeriodicTask, "Periodic", 100, (void*)&mes, 3, NULL);
	}
	


	xQueue1 = xQueueCreate(2, sizeof(char*));
	xQueue2 = xQueueCreate(2, sizeof(char*));
	xQueueSet = xQueueCreateSet(2*2);

	xQueueAddToSet(xQueue1, xQueueSet);
	xQueueAddToSet(xQueue2, xQueueSet);
	
	//if(xQueue != NULL)
	{
		xTaskCreate(TASK_LED2_Blinky,"send1", 200, (void*)100, 2, NULL);
		xTaskCreate(TASK_LED2_Blinky,"send2", 200, (void*)200, 2, NULL);
		xTaskCreate(TASK_LED1_Blinky,"rec", 200, NULL, 3, NULL);
	}
	//xTaskCreate(TASK_LED1_Blinky,"led",200,NULL,2,NULL);
	//xTaskCreate(TASK_LED2_Blinky,"led1",200,NULL,1,NULL);


	flag = readRSTFLAG();
	sprintf(string, "flag:%d\n", flag);
	uart_send(PRINTF_UART, string, strlen(string));
	clrRSFLAG(0);


#define mainONE_SHOT_TIMER_PERIOD pdMS_TO_TICKS( 3333 )
#define mainAUTO_RELOAD_TIMER_PERIOD pdMS_TO_TICKS( 500 )


	TimerHandle_t timer1, timer2;
	BaseType_t ret1, ret2;

	timer1 = xTimerCreate("oneShot", mainONE_SHOT_TIMER_PERIOD,
								pdFALSE,
								NULL,
								oneShot);

	timer2 = xTimerCreate("AutoReload", mainAUTO_RELOAD_TIMER_PERIOD,
								pdPASS,
								NULL,
								autoReload);

	if(timer1 == NULL || timer2 == NULL)
	{
		while(1)
		{
			LED_Flash(8, ALARM_R_);
		}
	}

	ret1 = xTimerStart(timer1, 0);
	ret2 = xTimerStart(timer2, 0);
	if(ret1 == pdFALSE || ret2 == pdFALSE)
	{
		while(1)
		{
			LED_Flash(8, ALARM_R_);
		}
	}
#endif

	vTaskStartScheduler();

	for(;;)
	{
/*heap memory overflow*/
		//LED_Flash(8, ALARM_R_);
		//IWDT_Clr();
	}
	return 0;
}
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

extern uint32 uIDLERunCount;
void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
	uIDLERunCount++;
	vCoRoutineSchedule();
	return;
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
		//softReset();
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()).  The code in this
	tick hook implementation is for demonstration only - it has no real
	purpose.  It just gives a semaphore every 50ms.  The semaphore unblocks a
	task that then toggles an LED.  Additionally, the call to
	vQueueSetAccessQueueSetFromISR() is part of the "standard demo tasks"
	functionality. */

	/* The semaphore and associated task are not created when the simple blinky
	demo is used. */
	#if mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 0
	{
	static unsigned long ulLastGiveTime = 0UL;
	const unsigned long ulRate = 50UL / portTICK_PERIOD_MS;
	extern SemaphoreHandle_t xLEDSemaphore;

		configASSERT( xLEDSemaphore );

		if( ( xTaskGetTickCountFromISR() - ulLastGiveTime ) > ulRate )
		{
			/* The second parameter is normally used to determine if a context
			switch should be performed or not.  In this case the function is
			being performed from the tick hook, so the scheduler will make that
			assessment before returning to a task anyway - so the parameter is
			not needed and is just set to NULL. */
			xSemaphoreGiveFromISR( xLEDSemaphore, NULL );
			ulLastGiveTime += ulRate;
		}

		/* Write to a queue that is in use as part of the queue set demo to
		demonstrate using queue sets from an ISR. */
		vQueueSetAccessQueueSetFromISR();
	}
	#endif /* mainCREATE_SIMPLE_BLINKY_DEMO_ONLY */
}
/*-----------------------------------------------------------*/

#ifdef JUST_AN_EXAMPLE_ISR

void Dummy_IRQHandler(void)
{
long lHigherPriorityTaskWoken = pdFALSE;

	/* Clear the interrupt if necessary. */
	Dummy_ClearITPendingBit();

	/* This interrupt does nothing more than demonstrate how to synchronise a
	task with an interrupt.  A semaphore is used for this purpose.  Note
	lHigherPriorityTaskWoken is initialised to zero. Only FreeRTOS API functions
	that end in "FromISR" can be called from an ISR. */
	xSemaphoreGiveFromISR( xTestSemaphore, &lHigherPriorityTaskWoken );

	/* If there was a task that was blocked on the semaphore, and giving the
	semaphore caused the task to unblock, and the unblocked task has a priority
	higher than the current Running state task (the task that this interrupt
	interrupted), then lHigherPriorityTaskWoken will have been set to pdTRUE
	internally within xSemaphoreGiveFromISR().  Passing pdTRUE into the
	portEND_SWITCHING_ISR() macro will result in a context switch being pended to
	ensure this interrupt returns directly to the unblocked, higher priority,
	task.  Passing pdFALSE into portEND_SWITCHING_ISR() has no effect. */
	portEND_SWITCHING_ISR( lHigherPriorityTaskWoken );
}

#endif /* JUST_AN_EXAMPLE_ISR */




